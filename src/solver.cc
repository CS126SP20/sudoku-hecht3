// Copyright 2020 [Your Name]. All rights reserved.

#include <sudoku/solver.h>
#include <sudoku/sudoku_game.h>
#include <iostream>
#include <cmath>

const int kMaxMove = 9;
const int kMinMove = 1;
// According to https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-s095-programming-for-the-puzzled-january-iap-2018/puzzle-8-you-wont-want-to-play-sudoku-again/MIT6_S095IAP18_Puzzle_8.pdf
// the hardest sudoku puzzle ever created takes this many backtracks.
// In terms of our program, this many backtracks is still takes under a second.
const int kMaxBackTracks = 335578;

// https://www.youtube.com/watch?v=auK3PSZoidc was used as a reference in
// creating this algorithm. No code was taken directly from it
// (the example in the video was in python)

std::vector<int> FindEmptyCell(const int (&board)[kColLength][kRowLength]);

bool CheckValidMove(const int (&board)[kColLength][kRowLength], int i,
                    int j, int move);

bool sudoku::solver::Solve(int (&board)[kColLength][kRowLength]) {
  backtracks++;
  if (backtracks < kMaxBackTracks + 1) {
    std::vector<int> nextEmptyCell;
    nextEmptyCell = FindEmptyCell(board);
    if (nextEmptyCell[0] == -1) {
      StoreBoard(board);
      return true;
    }
    for (int move = kMinMove; move <= kMaxMove; move++) {
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
}

std::vector<int> FindEmptyCell(const int (&board)[kColLength][kRowLength]) {
  std::vector<int> coords{-1, -1};
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

bool CheckValidMove(const int (&board)[kColLength][kRowLength],
                                    int i, int j, int move) {
  bool rowValid = true;
  for (int p = 0; p < kRowLength; p++) {
    if (move == board[i][p]) {
      rowValid = false;
    }
  }
  bool colValid = true;
  bool sectorValid = true;
  if (rowValid) {
    for (int p = 0; p < kColLength; p++) {
      if (move == board[p][j]) {
        colValid = false;
      }
    }
    if (colValid) {
      int sectorLeft = kSectorSize * floor(i / kSectorSize);
      int sectorTop = kSectorSize * floor(j / kSectorSize);
      for (int p = sectorLeft; p < sectorLeft + kSectorSize; p++) {
        for (int q = sectorTop; q < sectorTop + kSectorSize; q++) {
          if (board[p][q] == move) {
            sectorValid = false;
          }
        }
      }
    }
  }
  return (rowValid && colValid && sectorValid);
}

void sudoku::solver::StoreBoard(const int (&board)[kColLength][kRowLength]) {
  for (int i = 0; i < kColLength; i++) {
    for (int j = 0; j < kRowLength; j++) {
      public_board[i][j] = board[i][j];
    }
  }
}
