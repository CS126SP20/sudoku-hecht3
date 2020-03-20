//
// Created by connell on 3/12/20.
//

#ifndef SUDOKU_SUDOKU_GAME_H
#define SUDOKU_SUDOKU_GAME_H

#include <string>


class sudoku_game {
  public:
    explicit sudoku_game(std::string SPFile);
    explicit sudoku_game(std::istream &SPFile);

  bool CheckValidSPF(const std::string& boards);
};


#endif //SUDOKU_SUDOKU_GAME_H
