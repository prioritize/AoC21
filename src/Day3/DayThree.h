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
#include <cmath>
#include <list>
#include "fmt/core.h"

using std::string;
using std::vector;
using std::ifstream;
using std::stringstream;

struct Binary {
    int zero = 0;
    int one = 0;
};

int stringToBinary(string s);
void printList(std::list<string> l);
class DayThree {
public:
    string fname;
    vector<string> rawInput;
    vector<string> parsedInput;
    vector<Binary> frequencies;
    string epsilon;
    string gamma;
    int e = 0;
    int g = 0;
    explicit DayThree(std::string fname) : fname(std::move(fname)) {}
    void parseInput();
    void parsePuzzlePart1();
    void parsePuzzlePart2();
    void makeBinary();
    string makeOxygenRating();
    string makeCO2Rating();
    char mostCommonVert(uint32_t idx, char favor, const std::list<string>& input);
};


#endif //AOC21_DAYTHREE_H
