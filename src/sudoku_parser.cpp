//
// Created by connell on 3/12/20.
//

#include "sudoku/sudoku_parser.h"
#include <iostream>
#include <sstream>
#include <sudoku/sudoku_game.h>
#include <sudoku/solver.h>

std::vector<sudoku::solver> solvers;

std::istream &operator>>(std::istream &input, sudoku_parser &games) {
  // The following iterator was taken from
  // https://en.cppreference.com/w/cpp/iterator/istreambuf_iterator
  std::string contents((std::istreambuf_iterator<char>(input)),
                       std::istreambuf_iterator<char>());
  games.boards.append(contents.c_str());
  if (games.CheckValidSPF(games.boards)) {
    // The input is left as the string of boards and the boards are then split
    // into games
    games.SplitIntoGames(games.boards, '\n');
  } else {
    // -1 is assigned to the input through this command
    input >> games.boards;
  }
  return input;
}

std::ostream &operator<<(std::ostream &output, sudoku_parser const &games) {
  output << '\n';
  for (int s = 0; s < solvers.size(); s++) {
    if (solvers[s].public_board[0][0] == 0) {
      std::string to_output = "Game ";
      to_output.append(std::to_string(s));
      to_output.append(" was not solvable.\n\n");
      output << to_output;
    } else {
      std::string to_output = "Game ";
      to_output.append(std::to_string(s));
      to_output.append(" was solvable:\n");
      to_output.append("╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n");
      for (int i = 0; i < kColLength; i++) {
        to_output.append("║ ");
        for (int j = 0; j < kRowLength; j++) {
          to_output.append(std::to_string(solvers[s].public_board[i][j]));
          // We have to subtract one from these constants because the array is
          // 0-indexed
          if (j < kSectorSize - 1 || j % kSectorSize != kSectorSize - 1) {
            to_output.append(" │ ");
          } else {
            to_output.append(" ║ ");
          }
        }
        if (i != kColLength - 1 && i % kSectorSize != kSectorSize - 1) {
          to_output.append("\n╟───┼───┼───╫───┼───┼───╫───┼───┼───╢");
        } else if (i != kColLength - 1 && i % kSectorSize == kSectorSize - 1) {
          to_output.append("\n╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣");
        }
        to_output.append("\n");
      }
      to_output.append("╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n");
      to_output.append("\n");
      output << to_output;
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
  std::vector<int> new_line_locations;
  for (int i = 0; i < boards.size(); i++) {
    if (boards[i] == '\n') {
      new_line_locations.push_back(i);
    }
  }
  for (int i = 0; i < new_line_locations.size(); i++) {
    if (boards.substr(new_line_locations[i],
                   boards.find_first_of('\n',
                  new_line_locations[i] + 1) - new_line_locations[i]).size() - 1
                      != kColLength * kRowLength) {
      return false;
    }
  }
  if (new_line_locations.size() > boards.size() / (kColLength * kRowLength)) {
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
      solve.backtracks = 0;
      solve.Solve(to_solve.game_arr);
      solvers.push_back(solve);
    }
    is_first = false;
  }
}



