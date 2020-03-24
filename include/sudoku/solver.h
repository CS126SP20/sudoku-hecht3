// Copyright (c) 2020 [Your Name]. All rights reserved.

#ifndef SUDOKU_SOLVER_H_
#define SUDOKU_SOLVER_H_

#include <sudoku/sudoku_parser.h>

namespace sudoku {
  class solver {
  public:
    int **board_to_print;

    bool Solve(int (&board)[kColLength][kRowLength]);

    std::vector<int> FindEmptyCell(const int (&board)[kColLength][kRowLength]);

    bool
    CheckValidMove(const int (&board)[kColLength][kRowLength], int i, int j,
                   int move);

    void PrintBoard(const int (&board)[kColLength][kRowLength]);
  };

}  // namespace sudoku

#endif  // SUDOKU_SOLVER_H_
