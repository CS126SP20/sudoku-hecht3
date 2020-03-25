// Copyright (c) 2020 [Your Name]. All rights reserved.

#ifndef SUDOKU_SOLVER_H_
#define SUDOKU_SOLVER_H_

#include "sudoku_game.h"

namespace sudoku {
  class solver {
   /**
    * Stores the final solution board in a variable that can be accessed by
    * the overloaded >> operator for being sent to an ostream.
    *
    * @param board the 2D array representing the solved board
    */
    void StoreBoard(const int (&board)[kColLength][kRowLength]);

  public:
    /** The public solved board assigned after the solve method is done. */
    int public_board[kColLength][kRowLength];
    /** The number of backtracks required to solve the board. */
    int backtracks;

    /**
    * Checks to see if a given move in a specified location is valid for the
    * current board.
    *
    * @param board the 2D array representing the solved board
    * @param i the 1st dimension location on the board for potential move
    * @param j the 2nd dimension location on the board for potential move
    * @param move the move to be checked
    * @return whether or not the move was valid
    */
    bool CheckValidMove(const int (&board)[kColLength][kRowLength], int i,
                        int j, int move);

    /**
    * Solves a given board using recursion. Uses backtracking to fill in open
    * board positions
    *
    * @param board the 2D array representing the solved board
    * @return whether or not the board is solvable
    */
    bool Solve(int (&board)[kColLength][kRowLength]);
  };
}  // namespace sudoku

#endif  // SUDOKU_SOLVER_H_
