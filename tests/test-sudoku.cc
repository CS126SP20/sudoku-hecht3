// Copyright (c) 2020 connell. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <sudoku/solver.h>
#include <sudoku/sudoku_game.h>


// TODO(you): Remove this unnecessary test case.
TEST_CASE("Sanity Check", "[addition]") {
  sudoku_game* parser = new sudoku_game("data/emptyBoard.spf");
  REQUIRE(true);
}
