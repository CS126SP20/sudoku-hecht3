//
// Created by connell on 3/21/20.
//

#ifndef SUDOKU_SUDOKU_GAME_H
#define SUDOKU_SUDOKU_GAME_H

#include <string>
#include <vector>
#include <sudoku/sudoku_parser.h>


class sudoku_game {
  public:
    explicit sudoku_game(std::string game_as_string);
    std::string game_string;
};


#endif //SUDOKU_SUDOKU_GAME_H
