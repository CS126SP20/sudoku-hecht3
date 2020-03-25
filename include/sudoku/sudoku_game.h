//
// Created by connell on 3/21/20.
//

#ifndef SUDOKU_SUDOKU_GAME_H
#define SUDOKU_SUDOKU_GAME_H

#include <string>
#include <vector>
#include <functional>

/** The length of each column on the board. */
const int kColLength = 9;
/** The length of each row on the board. */
const int kRowLength = 9;
/** The size of each square sector on the board. */
const int kSectorSize = 3;

class sudoku_game {
public:
 /**
  * The constructor for a single sudoku game. Takes a string and turns it into
  * a 2D array representing a game board.
  *
  * @param game_as_string the game represented as a string from the spf file
  */
  explicit sudoku_game(std::string game_as_string);

  /** The public array representing a game. */
  int game_arr[kColLength][kRowLength];
};

#endif //SUDOKU_SUDOKU_GAME_H
