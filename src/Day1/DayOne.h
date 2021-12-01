//
// Created by leach on 11/30/2021.
//

#ifndef AOC21_DAYONE_H
#define AOC21_DAYONE_H
#include "fmt/core.h"
#include <vector>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
using std::string;
using std::vector;


class DayOne {
public:
    string fname;
    vector<int> rawInput;
    int depthIncreases = 0;
    int slidingDepths = 0;
    explicit DayOne(std::string inputFile) : fname(std::move(inputFile)) {};
    void parseInput();
    void parsePuzzle();
    void parsePuzzleTwo();
};


#endif //AOC21_DAYONE_H
