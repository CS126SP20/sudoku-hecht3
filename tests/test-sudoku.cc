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


