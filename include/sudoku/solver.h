// Copyright (c) 2020 [Your Name]. All rights reserved.

#ifndef SUDOKU_SOLVER_H_
#define SUDOKU_SOLVER_H_
#include <sudoku/sudoku_parser.h>

namespace sudoku {
  class solver {
    public:
      bool Solve(char board[kColLength][kRowLength]);
      std::vector<int> FindEmptyCell(char board[kColLength][kRowLength]);
      bool CheckValidMove(char board[kColLength][kRowLength], int i, int j, int move);
      void PrintBoard(char board[kColLength][kRowLength]);
  };

}  // namespace sudoku

#endif  // SUDOKU_SOLVER_H_

