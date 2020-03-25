// Copyright (c) 2020 [Your Name]. All rights reserved.

#ifndef SUDOKU_SOLVER_H_
#define SUDOKU_SOLVER_H_

#include "sudoku_game.h"

namespace sudoku {
  class solver {
    void StoreBoard(const int (&board)[kColLength][kRowLength]);

  public:
    int public_board[kColLength][kRowLength];
    int backtracks;

    bool Solve(int (&board)[kColLength][kRowLength]);
  };
}  // namespace sudoku

#endif  // SUDOKU_SOLVER_H_
