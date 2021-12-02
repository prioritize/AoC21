//
// Created by leach on 12/1/2021.
//

#ifndef AOC21_DAYTHREE_H
#define AOC21_DAYTHREE_H
#include <string>
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include "fmt/core.h"

using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;

class DayThree {
public:
    string fname;
    vector<string> rawInput;
    vector<string> parsedInput;
    explicit DayThree(std::string fname) : fname(std::move(fname)) {}
    void parseInput();
    void parsePuzzlePart1();
    void parsePuzzlePart2();
};


#endif //AOC21_DAYTHREE_H
