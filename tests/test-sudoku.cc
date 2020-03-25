// Copyright (c) 2020 connell. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <sudoku/sudoku_parser.h>
#include <sudoku/sudoku_game.h>

// CheckValidSPF test cases
// In testing this function I also test the >> operator overload because that is
// the function that calls CheckValidSPF with the contents of the file input.

// InvalidSPF tests
TEST_CASE("Unexpected character letter", "[InvalidSPF]") {
  std::ifstream puzzle_stream("data/unexpectedCharacterLetter.spf");
  sudoku_parser parser;
  std::istream &input_stream = puzzle_stream;
  input_stream >> parser;
  REQUIRE(input_stream.tellg() == -1);
}

TEST_CASE("Unexpected character special character", "[InvalidSPF]") {
  std::ifstream puzzle_stream
    ("data/unexpectedCharacterSpecialCharacter.spf");
  sudoku_parser parser;
  std::istream &input_stream = puzzle_stream;
  input_stream >> parser;
  REQUIRE(input_stream.tellg() == -1);
}

TEST_CASE("Puzzle too long", "[InvalidSPF]") {
  std::ifstream puzzle_stream("data/puzzleTooLong.spf");
  sudoku_parser parser;
  std::istream &input_stream = puzzle_stream;
  input_stream >> parser;
  REQUIRE(input_stream.tellg() == -1);
}

TEST_CASE("Puzzle too short", "[InvalidSPF]") {
  std::ifstream puzzle_stream("data/puzzleTooShort.spf");
  sudoku_parser parser;
  std::istream &input_stream = puzzle_stream;
  input_stream >> parser;
  REQUIRE(input_stream.tellg() == -1);
}

TEST_CASE("No spf1.0 at top", "[InvalidSPF]") {
  std::ifstream puzzle_stream("data/noSPF1.0.spf");
  sudoku_parser parser;
  std::istream &input_stream = puzzle_stream;
  input_stream >> parser;
  REQUIRE(input_stream.tellg() == -1);
}

// ValidSPF tests
TEST_CASE("Empty board", "[ValidSPF]") {
  std::ifstream puzzle_stream("data/emptyBoard.spf");
  sudoku_parser parser;
  std::istream &input_stream = puzzle_stream;
  input_stream >> parser;
  REQUIRE(input_stream.tellg() == 1*(kColLength * kRowLength + 1) + kSPFLength);
}

TEST_CASE("Two boards", "[ValidSPF]") {
  std::ifstream puzzle_stream("data/twoBoards.spf");
  sudoku_parser parser;
  std::istream &input_stream = puzzle_stream;
  input_stream >> parser;
  REQUIRE(input_stream.tellg() == 2*(kColLength * kRowLength + 1) + kSPFLength);
}

TEST_CASE("Three boards", "[ValidSPF]") {
  std::ifstream puzzle_stream("data/threeBoards.spf");
  sudoku_parser parser;
  std::istream &input_stream = puzzle_stream;
  std::ostream &output_stream = std::cout;
  input_stream >> parser;
  REQUIRE(input_stream.tellg() == 3*(kColLength * kRowLength + 1) + kSPFLength);
}

// Class sudoku_game really doesn't need to be tested becuase it's trivial --
// it just breaks up the given string into a 2D array.


TEST_CASE("CheckValidMoveInvalid", "[InvalidMove]") {
  std::string str = "246135879";
  str.append    (   "135879246");
  str.append    (   "879246135");
  str.append    (   "563412798");
  str.append    (   "412798563");
  str.append    (   "798563412");
  str.append    (   "654321987");
  str.append    (   "321987654");
  str.append    (   "987654321");
  sudoku_game to_solve = sudoku_game(str);
  sudoku::solver solve = sudoku::solver();
  // Because this is an already solved board, no move should be valid unless
  // it is identical to one already made
  REQUIRE(!solve.CheckValidMove(to_solve.game_arr, 5, 5, 2));
  REQUIRE(!solve.CheckValidMove(to_solve.game_arr, 6, 1, 7));
  REQUIRE(!solve.CheckValidMove(to_solve.game_arr, 3, 5, 2));
  REQUIRE(!solve.CheckValidMove(to_solve.game_arr, 5, 5, 2));
}

// Output operator overloading does not need to be tested because any issue
// with it would be fairly obvious -- the board gets printed out for the user
// once it's solved.

TEST_CASE("CheckValidMoveValid", "[ValidMove]") {
  std::string str = "246135879";
  str.append    (   "135879246");
  str.append    (   "879246135");
  str.append    (   "563412798");
  str.append    (   "412798563");
  str.append    (   "798563412");
  str.append    (   "654321987");
  str.append    (   "321987654");
  str.append    (   "987654321");
  sudoku_game to_solve = sudoku_game(str);
  sudoku::solver solve = sudoku::solver();
  // Because this is an already solved board, no move should be valid unless
  // it is identical to one already made. Because the function checks the given
  // move against the current board, we need to reset the positions of the moves
  // we want to check to 0.
  to_solve.game_arr[0][0] = 0;
  to_solve.game_arr[1][1] = 0;
  to_solve.game_arr[5][5] = 0;
  to_solve.game_arr[8][0] = 0;
  REQUIRE(solve.CheckValidMove(to_solve.game_arr, 0, 0, 2));
  REQUIRE(solve.CheckValidMove(to_solve.game_arr, 1, 1, 3));
  REQUIRE(solve.CheckValidMove(to_solve.game_arr, 5, 5, 3));
  REQUIRE(solve.CheckValidMove(to_solve.game_arr, 8, 0, 9));
}