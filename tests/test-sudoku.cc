// Copyright (c) 2020 connell. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <sudoku/solver.h>
#include <sudoku/sudoku_parser.h>


TEST_CASE("Sanity Check", "[addition]") {
  std::ifstream puzzle_stream("data/emptyBoard.spf");
  sudoku_parser parser;
  std::istream& input_stream = puzzle_stream;
  std::ostream& output_stream = std::cout;
  std::string tag;
  parser.boards[0];
  input_stream >> parser;
  output_stream << parser;
  REQUIRE(true);
}
