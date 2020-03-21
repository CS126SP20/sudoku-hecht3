//
// Created by connell on 3/12/20.
//

#ifndef SUDOKU_SUDOKU_PARSER_H
#define SUDOKU_SUDOKU_PARSER_H

#include <string>
#include <sudoku/sudoku_game.h>

class sudoku_parser {
  bool CheckValidSPF(const std::string &boards);
  std::vector<std::string> Split(const std::string& s, char delimiter);
  public:
    std::string boards;
    friend std::istream& operator >> (std::istream &input, sudoku_parser &game);
    friend std::ostream &operator << (std::ostream &output, sudoku_parser const& game);
};

#endif //SUDOKU_SUDOKU_PARSER_H
