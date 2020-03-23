// Copyright 2020 [Your Name]. All rights reserved.

#include <sudoku/solver.h>
#include <sudoku/sudoku_game.h>
#include <cmath>
#include <iostream>

const int kSectorSize = 3;

class solver {

};

bool sudoku::solver::Solve(int board[kColLength][kRowLength]) {
  std::vector<int> nextEmptyCell;
  nextEmptyCell = FindEmptyCell(board);
  if (nextEmptyCell[0] == -1) {
    PrintBoard(board);
    return true;
  }
  for (int move = 1; move < 10; move++) {
    if (CheckValidMove(board, nextEmptyCell[0], nextEmptyCell[1], move)) {
      board[nextEmptyCell[0]][nextEmptyCell[1]] = move;
      if (Solve(board)) {
        return true;
      }
      board[nextEmptyCell[0]][nextEmptyCell[1]] = 0;
    }
  }
  return false;
}

std::vector<int>
sudoku::solver::FindEmptyCell(int board[kColLength][kRowLength]) {
  std::vector<int> coords {-1, -1};
  for (int i = 0; i < kColLength; i++) {
    for (int j = 0; j < kRowLength; j++) {
      if (board[i][j] == 0) {
        coords[0] = i;
        coords[1] = j;
      }
    }
  }
  return coords;
}

