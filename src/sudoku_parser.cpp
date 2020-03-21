//
// Created by connell on 3/12/20.
//

#include <fstream>
#include <vector>
#include "sudoku/sudoku_parser.h"
#include <iostream>
#include <sstream>

namespace sudoku {
  const int kSPFLength = 6;
  const int kColLength = 9;
  const int kRowLength = 9;

  class sudoku_parser {
    std::string fileInputString;
    bool isValid;
    public:
      std::string boards;
      friend std::istream &operator >> (std::istream &input, sudoku_parser const& game);
      friend std::ostream &operator << (std::ostream &output, sudoku_parser const& game);

      // The following function was taken from https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
      // It is used to split a string by a specified character.
      std::vector<std::string> Split(const std::string& s, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, delimiter))
        {
          tokens.push_back(token);
        }
        return tokens;
      }
      bool CheckValidSPF(std::string boards) {
        if (!(boards.substr(0, kSPFLength) == "#spf1.0")
            || boards.find_first_not_of("_0123456789\n", kSPFLength + 1) != std::string::npos
            || boards.find_first_of('\n') != kSPFLength + 1) {
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
      }
  };

} // namespace sudoku

std::istream &operator >> (std::istream &input, sudoku_parser &games) {
  std::string contents((std::istreambuf_iterator<char>(input)),
                       std::istreambuf_iterator<char>());
  games.boards.append(contents.c_str());
  if (games.CheckValidSPF(games.boards)) {
    input >> games.boards;
    std::vector<std::string> board_vec;
    board_vec = games.Split(games.boards, '\n');
    std::vector<sudoku_game> boards_as_games;
    for(int i = 0; i < board_vec.size(); i++) {
      boards_as_games[i] = new sudoku_game(board_vec[i])
    }
  }
  return input;
}

std::ostream &operator << (std::ostream &output, sudoku_parser const& game) {
  output << game.boards;

}
