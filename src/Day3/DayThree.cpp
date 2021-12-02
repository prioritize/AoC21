//
// Created by leach on 12/1/2021.
//

#include "DayThree.h"

void DayThree::parseInput() {
    ifstream inFile("input3.txt");
    if (!inFile.is_open()) {
        fmt::print("Unable to open input file\n");
        exit(1);
    }
    stringstream buffer;
    string temp;
    while (getline(inFile, temp)) {
        rawInput.push_back(temp);
    }
    std::regex c(R"(([a-z]{1,7})\s(\d))");

    for (auto& l : rawInput) {
        std::sregex_iterator currentMatch(l.begin(), l.end(), c);
        std::sregex_iterator lastMatch;
        std::smatch match = *currentMatch;
        while (currentMatch != lastMatch) {
            if (match.ready()) {
//                parsedInput.push_back({match[1], std::stoi(match[2])});
            }
            currentMatch++;
        }
    }
}
void DayThree::parsePuzzlePart1() {

}

void DayThree::parsePuzzlePart2() {

}

