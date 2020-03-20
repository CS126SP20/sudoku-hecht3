//
// Created by connell on 3/12/20.
//

#include <fstream>
#include <vector>
#include "sudoku/sudoku_game.h"
#include <iostream>

namespace sudoku {
  class sudoku_game {
      std::string fileInputString;
      std::vector<std::string> boards;

      public:
        explicit sudoku_game(std::string& SPFile) {
          fileInputString = SPFile;
          std::ifstream file;
          file.open(SPFile);
          if (!file.is_open()) {
            std::cout << "invalid file given";
          } else {
            std::string line;
            getline(file, line);
            boards.push_back(line);
          }
        }
        explicit sudoku_game(std::istream &SPFile) {
          // The following is from: https://stackoverflow.com/questions/18398167/how-to-copy-a-txt-file-to-a-char-array-in-c
          std::string contents((std::istreambuf_iterator<char>(SPFile)),
                               std::istreambuf_iterator<char>());
          std::string boards = contents.c_str();
        }
        friend std::istream &operator >> (std::istream &input, sudoku_game game);

      bool CheckValidBoard(std::string& board) {


      }
  };
  std::istream &operator >> (std::istream &input, sudoku_game game) {
    input >> game.fileInputString;
    return input;
  }
} // namespace sudoku