// Copyright (c) 2020 [Your Name]. All rights reserved.

#ifndef SUDOKU_SOLVER_H_
#define SUDOKU_SOLVER_H_
#include <sudoku/sudoku_parser.h>


namespace sudoku {
    class solver {
      std::string board;
      public:
        explicit solver(std::string &to_solve);
    };

}  // namespace sudoku

#endif  // SUDOKU_SOLVER_H_

