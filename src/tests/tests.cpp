//
// Created by leach on 11/24/2021.
//

#include <gtest/gtest.h>
#include "../Day1/DayOne.h"
#include "../Day2/DayTwo.h"
#include "../Day3/DayThree.h"

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
TEST(TestDayThree, TestParsePuzzlePart1) {
    DayThree dayThree("input3.txt");
    dayThree.parseInput();
    dayThree.makeBinary();
    for (auto& i : dayThree.frequencies) {
        fmt::print("{} ", i.zero);
    }
    fmt::print("\n");
    for (auto& i : dayThree.frequencies) {
        fmt::print("{} ", i.one);
    }
    fmt::print("\n");
}

TEST (TestDayThree, TestMakeOxygenRating) {
    DayThree dayThree("input3.txt");
    dayThree.parseInput();
    int o2Rating = stringToBinary(dayThree.makeOxygenRating());
    int co2Rating = stringToBinary(dayThree.makeCO2Rating());
    fmt::print("o2rating: {}\n", o2Rating);
    fmt::print("co2rating: {}\n", co2Rating);
    fmt::print("life support rating: {}\n", o2Rating * co2Rating);
}