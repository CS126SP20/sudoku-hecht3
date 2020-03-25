//
// Created by connell on 3/12/20.
//

#ifndef SUDOKU_SUDOKU_PARSER_H
#define SUDOKU_SUDOKU_PARSER_H

#include <string>
#include <vector>
#include "solver.h"

/** The length of the characters "spf1.0". */
const int kSPFLength = 7;

class sudoku_parser {

 /**
  * Checks if an spf file is valid and if the games are capable of being put
  * into the solver method
  *
  * @param boards the string representing the boards from the spf file
  * @return whether or not the spf is valid
  */
  bool CheckValidSPF(std::string &boards);

 /**
  * Splits the spf as a string into individual sudoku_game and then calls
  * solve() on them.
  *
  * @param games the games represented as a string from the spf file
  * @param delimiter the delimiter (in this case '\n' that will be used to split
  *        the games string up into games
  */
  void SplitIntoGames(const std::string &games, char delimiter);

public:
  std::vector<sudoku::solver> solvers;

  std::string boards;

  /**
  * Overloads the >> operator to take an SPF file as an input
  *
  * @param input the istream instance that contains the game data
  * @param game the instance of sudoku_parser relevant to this operator use
  * @return the istream with the new game information in it
  */
  friend std::istream &operator>>(std::istream &input, sudoku_parser &game);

  /**
  * Overloads the << operator to print a game board nicely
  *
  * @param output the ostream instance that the board will be sent to
  * @param game the instance of sudoku_parser relevant to this operator use
  * @return the ostream with the new game board information in it
  */
  friend std::ostream
  &operator<<(std::ostream &output, sudoku_parser const &game);
};

#endif //SUDOKU_SUDOKU_PARSER_H
