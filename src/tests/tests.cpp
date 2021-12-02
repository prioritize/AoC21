//
// Created by leach on 11/24/2021.
//

#include <gtest/gtest.h>
#include "../Day1/DayOne.h"
#include "../Day2/DayTwo.h"

TEST(Tests, Test1) {
    EXPECT_EQ(1, 1);
}

TEST(TestDay1, TestReadInput) {
    DayOne dayOne("input.txt");
    dayOne.parseInput();
    for (auto& i : dayOne.rawInput) {
        fmt::print("{}\n", i);
    }
}

TEST(TestDay1, TestParsePuzzle) {
    DayOne dayOne("input.txt");
    dayOne.parseInput();
    dayOne.parsePuzzle();
    dayOne.parsePuzzleTwo();
}
TEST(TestDayTwo, TestParsePuzzlePart1) {
    DayTwo dayTwo("input2.txt");
    dayTwo.parseInput();
    dayTwo.parsePuzzlePart1();
}

TEST(TestDayTwo, TestParsePuzzlePart2) {
    DayTwo dayTwo("input2.txt");
    dayTwo.parseInput();
    dayTwo.parsePuzzlePart2();
}
