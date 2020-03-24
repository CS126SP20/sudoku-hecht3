//
// Created by connell on 3/21/20.
//

#include <iostream>
#include "sudoku/sudoku_game.h"

sudoku_game::sudoku_game(std::string game_as_string) {
  std::string game_string = game_as_string;
  int counter = 0;
  for (int i = 0; i < kColLength; i++) {
    for (int j = 0; j < kRowLength; j++) {
      if (game_string[counter] == '_') {
        game_vec[i][j] = 0;
      } else {
        int num = game_string[counter] - '0';
        game_vec[i][j] = num;
      }
      counter++;
    }
  }
}
