//
// Created by connell on 3/12/20.
//

#include "sudoku/sudoku_parser.h"
#include <iostream>
#include <sstream>
#include <sudoku/sudoku_game.h>
#include <sudoku/solver.h>

std::vector<sudoku::solver> solvers;
std::vector<bool> solvable;

std::istream &operator>>(std::istream &input, sudoku_parser &games) {
  // The following iterator was taken from
  // https://en.cppreference.com/w/cpp/iterator/istreambuf_iterator
  std::string contents((std::istreambuf_iterator<char>(input)),
                       std::istreambuf_iterator<char>());
  games.boards.append(contents.c_str());
  if (games.CheckValidSPF(games.boards)) {
    input >> games.boards;
    games.SplitIntoGames(games.boards, '\n');
  }
  return input;
}

std::ostream &operator<<(std::ostream &output, sudoku_parser const &games) {
  output << '\n';
  for (int s = 0; s < solvers.size(); s++) {
    if (solvers[s].public_board[0][0] == 0) {
      std::cout << "Game ";
      std::cout << s;
      std::cout << " was not solvable\n\n";
    } else {
      std::cout << "Game ";
      std::cout << s;
      std::cout << " was solvable:\n";
      output << "╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n";
      for (int i = 0; i < kColLength; i++) {
        output << "║ ";
        for (int j = 0; j < kRowLength; j++) {
          output << solvers[s].public_board[i][j];
          // We have to subtract one from these constants because the array is
          // 0-indexed
          if (j < kSectorSize - 1 || j % kSectorSize != kSectorSize - 1) {
            output << " │ ";
          } else {
            output << " ║ ";
          }
        }
        if (i != kColLength - 1 && i % kSectorSize != kSectorSize - 1) {
          output << "\n╟───┼───┼───╫───┼───┼───╫───┼───┼───╢";
        } else if (i != kColLength - 1 && i % kSectorSize == kSectorSize - 1) {
          output << "\n╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣";
        }
        output << '\n';
      }
      output << "╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n";
      output << '\n';
    }
  }
}

bool sudoku_parser::CheckValidSPF(std::string &boards) {
  if (!(boards.substr(0, kSPFLength) == "#spf1.0")
      || (boards.find_first_not_of("_123456789\n", kSPFLength + 1)
          != std::string::npos)
      || (boards.find_first_of('\n') != kSPFLength)) {
    return false;
  }
  int new_line_count = 0;
  for (int i = 0; i < boards.size(); i++) {
    if (boards[i] == '\n') {
      new_line_count++;
    }
  }
  if (new_line_count > boards.size() / (kColLength * kRowLength)) {
    return false;
  }
  return true;
}

// The following function was taken from https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
// It is used to split a string by a specified character.
void sudoku_parser::SplitIntoGames(const std::string &s, char delimiter) {
  std::vector<sudoku_game> boards_as_games;
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(s);
  bool is_first = true;
  // Added the above boolean to exclude the #spf1.0 line
  while (std::getline(tokenStream, token, delimiter)) {
    if (!is_first) {
      std::string &str = token;
      sudoku_game to_solve = sudoku_game(str);
      sudoku::solver solve = sudoku::solver();
      bool solved;
      solve.backtracks = 0;
      solved = solve.Solve(to_solve.game_arr);
      solvable.push_back(solved);
      solvers.push_back(solve);
    }
    is_first = false;
  }
}



