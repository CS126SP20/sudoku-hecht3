//
// Created by connell on 3/12/20.
//

#ifndef SUDOKU_SUDOKU_PARSER_H
#define SUDOKU_SUDOKU_PARSER_H

#include <string>
#include <vector>
#include <sudoku/sudoku_game.h>

const int kSPFLength = 7;

class sudoku_parser {
  bool CheckValidSPF(std::string &boards);
  std::vector<std::reference_wrapper<sudoku_game>> SplitIntoGames(const std::string& s, char delimiter);
  public:
    std::string boards;
    friend std::istream &operator >> (std::istream &input, sudoku_parser &game);
    friend std::ostream &operator << (std::ostream &output, sudoku_parser const& game);
};

#endif //SUDOKU_SUDOKU_PARSER_H
