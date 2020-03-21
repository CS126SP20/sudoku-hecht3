//
// Created by connell on 3/21/20.
//

#include "sudoku/sudoku_game.h"

namespace sudoku {
  const int kSPFLength = 6;
  const int kColLength = 9;
  const int kRowLength = 9;
  class sudoku_game {
    std::string game_string;
    sudoku_game(const std::string &game_as_string) {
      game_string = game_as_string;
      std::vector<std::vector<char>> game_vec;
      int counter = 0;
      for (int i = 0; i < kColLength; i++) {
        for (int j = 0; j < kRowLength; j++) {
          game_vec[i][j] = game_string[counter];
          counter++;
        }
      }
    }
  };
}