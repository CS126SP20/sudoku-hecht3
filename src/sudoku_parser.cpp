//
// Created by connell on 3/12/20.
//

#include <fstream>
#include <vector>
#include <list>
#include "sudoku/sudoku_parser.h"
#include <iostream>
#include <sstream>
#include <sudoku/solver.h>
#include <functional>

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
  output << games.boards;
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
std::vector<std::reference_wrapper<sudoku_game>>
sudoku_parser::SplitIntoGames(const std::string &s, char delimiter) {
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
      solve.Solve(to_solve.game_arr);
    }
    is_first = false;
  }
  //return std::vector<std::reference_wrapper<sudoku_game>>(boards_as_games.begin(), boards_as_games.end());
}



