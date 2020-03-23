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

class sudoku_game {
  public:
    explicit sudoku_game(std::string game_as_string);
    char game_vec[kColLength][kRowLength];
};


#endif //SUDOKU_SUDOKU_GAME_H
