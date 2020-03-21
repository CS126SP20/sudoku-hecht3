// Copyright 2020 [Your Name]. All rights reserved.

#include <sudoku/solver.h>


class solver {
  std::string boards;
  std::string Solve() {
    if (!CheckValidBoards(boards)) {

    }
    return "";
  }
  public:
    explicit solver(std::string &to_solve) {
      boards = to_solve;
    }
};

