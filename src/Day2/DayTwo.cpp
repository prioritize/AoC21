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
    std::regex c(R"(([a-z]{1,7})\s(\d))");

    for (auto& l : rawInput) {
        std::sregex_iterator currentMatch(l.begin(), l.end(), c);
        std::sregex_iterator lastMatch;
        std::smatch match = *currentMatch;
        while (currentMatch != lastMatch) {
            if (match.ready()) {
                parsedInput.push_back({match[1], std::stoi(match[2])});
            }
            currentMatch++;
        }
    }
}

void DayTwo::parsePuzzlePart1() {
    for (auto& e : parsedInput) {
        if (e.direction == "forward") {
            position.x += e.offset;
        }
        if (e.direction == "up") {
            int possible = position.y - e.offset;
            if (possible <= 0) {
                position.y = 0;
            } else {
                position.y = possible;
            }
        }
        if (e.direction == "down") {
            position.y += e.offset;
        }
    }
    fmt::print("{}", position.x * position.y);
}

void DayTwo::parsePuzzlePart2() {
    for (auto& e : parsedInput) {
        if (e.direction == "forward") {
            position.x += e.offset;
            position.y += e.offset * aim;
        }
        if (e.direction == "up") {
            aim -= e.offset;
        }
        if (e.direction == "down") {
            aim += e.offset;
        }
    }
    fmt::print("{}", position.x * position.y);
}