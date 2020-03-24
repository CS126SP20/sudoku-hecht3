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
        game_arr[i][j] = 0;
      } else {
        // Need to subtract the ASCII value of 0 from the given values because
        // they are stored as chars right now instead of ints.
        int num = game_string[counter] - '0';
        game_arr[i][j] = num;
      }
      counter++;
    }
  }
}
