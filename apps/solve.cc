// Copyright (c) 2020 [Your Name]. All rights reserved.

#include <sudoku/solver.h>
#include <sudoku/sudoku_parser.h>
#include <iostream>
#include <fstream>
#include <sstream>

void HandleFile(std::string puzzle);

int main(int argc, char** argv) {
  // There is always at least 1 argument -- the name of the program which we
  // don't care about
  if (argc == 1) {
    std::cout << "Please input a file " << std::endl;
    std::string file;
    std::cin >> file;
    HandleFile(file);
  } else {
    for (int i = 1; i < argc; i++) {
      HandleFile(argv[i]);
    }
  }
}

void HandleFile(std::string puzzle) {
  std::ifstream puzzle_stream(puzzle);
  if (puzzle_stream.fail()) {
    std::cout << "\nInvalid file" << std::endl;
  } else {
    sudoku_parser parser;
    std::istream& input_stream = puzzle_stream;
    std::ostream& output_stream = std::cout;
    input_stream >> parser;
    output_stream << parser;
  }
}