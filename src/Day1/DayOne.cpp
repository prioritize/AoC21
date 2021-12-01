//
// Created by leach on 11/30/2021.
//

#include "DayOne.h"

void DayOne::parseInput() {
    std::ifstream inFile("input1.txt");
    std::stringstream buffer;
    if (!inFile.is_open()) {
        fmt::print("Unable to open input file\n");
    }
    buffer << inFile.rdbuf();
    string temp;
    while (getline(buffer, temp)) {
        rawInput.push_back(stoi(temp));
    }
    inFile.close();
}

void DayOne::parsePuzzle() {
    for (int i = 1; i < rawInput.size(); i++) {
        int current = rawInput[i];
        int previous = rawInput[i - 1];
        if (current > previous) {
            depthIncreases++;
        }
    }
    fmt::print("Depth increases: {}\n", depthIncreases);
}
void DayOne::parsePuzzleTwo() {
    int i = 0;
    while (i + 3 < rawInput.size()) {
        int close, far;
        int offset = i;
        close = rawInput[offset] + rawInput[offset+1] + rawInput[offset+2];
        far = rawInput[offset + 1] + rawInput[offset+2] + rawInput[offset+3];
        if (far > close) {
            slidingDepths++;
        }
        i++;
    }
    fmt::print("Sliding depths: {}\n", slidingDepths);
}