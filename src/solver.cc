// Copyright 2020 [Your Name]. All rights reserved.

#include <sudoku/solver.h>
#include <sudoku/sudoku_game.h>
#include <cmath>
#include <iostream>


class solver {

};

bool sudoku::solver::Solve(char board[kColLength][kRowLength]) {
  std::vector<int> nextEmptyCell;
  nextEmptyCell = FindEmptyCell(board);
  if (nextEmptyCell[0] == -1) {
    PrintBoard(board);
    return true;
  }
  for (int move = 1; move < 10; move++) {
    if (CheckValidMove(board, nextEmptyCell[0], nextEmptyCell[1], move)) {
      board[nextEmptyCell[0]][nextEmptyCell[1]] = static_cast<char>(move);
      if (Solve(board)) {
        return true;
      }
      board[nextEmptyCell[0]][nextEmptyCell[1]] = '_';
    }
  }
  return false;
}


