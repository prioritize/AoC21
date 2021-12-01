//
// Created by leach on 12/1/2021.
//

#ifndef AOC21_DAYTWO_H
#define AOC21_DAYTWO_H
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

class DayTwo {
public:
    vector<string> rawInput;
    vector<string> parsedInput;
    string fname;
    explicit DayTwo(string fname) : fname(std::move(fname)) {}
    void parseInput();
    void parsePuzzle();

};


#endif //AOC21_DAYTWO_H
