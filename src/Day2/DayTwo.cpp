/*
 * Day Two problem for the Advent of Code 2021
 */

#include "DayTwo.h"

void DayTwo::parseInput() {
    ifstream inFile("input2.txt");
    if (!inFile.is_open()) {
        fmt::print("Unable to open input file\n");
        exit(1);
    }
    stringstream buffer;
    string temp;
    while (getline(inFile, temp)) {
        rawInput.push_back(temp);
    }
}

void DayTwo::parsePuzzle() {

}