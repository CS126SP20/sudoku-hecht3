//
// Created by connell on 3/21/20.
//

#ifndef SUDOKU_SUDOKU_GAME_H
#define SUDOKU_SUDOKU_GAME_H

#include <string>
#include <vector>
#include <functional>

const int kColLength = 9;
const int kRowLength = 9;
const int kSectorSize = 3;

class sudoku_game {
public:
  explicit sudoku_game(std::string game_as_string);

  int game_arr[kColLength][kRowLength];
};


#endif //SUDOKU_SUDOKU_GAME_H
