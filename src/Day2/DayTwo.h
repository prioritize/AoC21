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

struct ControlCommand {
    string direction;
    int offset;
};
struct Position {
    int x = 0;
    int y = 0;
};
class DayTwo {
public:
    vector<string> rawInput;
    vector<ControlCommand> parsedInput;
    string fname;
    Position position;
    int aim = 0;
    explicit DayTwo(string fname) : fname(std::move(fname)) {}
    void parseInput();
    void parsePuzzlePart1();
    void parsePuzzlePart2();

};


#endif //AOC21_DAYTWO_H
