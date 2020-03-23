//
// Created by connell on 3/21/20.
//

#include <iostream>
#include "sudoku/sudoku_game.h"


namespace sudoku {
  class sudoku_game {

  };
}

sudoku_game::sudoku_game(std::string game_as_string) {
  std::string game_string = game_as_string;
  int counter = 0;
  for (int i = 0; i < kColLength; i++) {
    for (int j = 0; j < kRowLength; j++) {
      std::cout << game_vec[i][j];
      game_vec[i][j] = game_string[counter];
      counter++;
    }
  }
}
