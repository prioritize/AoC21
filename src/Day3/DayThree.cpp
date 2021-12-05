//
// Created by leach on 12/1/2021.
//

#include "DayThree.h"

void DayThree::parseInput() {
    ifstream inFile(fname);
    if (!inFile.is_open()) {
        fmt::print("Unable to open input file\n");
        exit(1);
    }
    stringstream buffer;
    string temp;
    while (getline(inFile, temp)) {
        rawInput.push_back(temp);
    }
    // No regex needed:w

//    std::regex c(R"(([a-z]{1,7})\s(\d))");
//
//    for (auto& l : rawInput) {
//        std::sregex_iterator currentMatch(l.begin(), l.end(), c);
//        std::sregex_iterator lastMatch;
//        std::smatch match = *currentMatch;
//        while (currentMatch != lastMatch) {
//            if (match.ready()) {
////                parsedInput.push_back({match[1], std::stoi(match[2])});
//            }
//            currentMatch++;
//        }
//    }
    parsedInput = rawInput;
}
void DayThree::makeBinary() {
    frequencies = vector<Binary>(parsedInput[0].size());
    fmt::print("{}\n", frequencies.size());
    for (auto& l : parsedInput) {
        for (size_t i = 0; i < l.length(); i++) {
            if (l[i] == '0') {
               frequencies[i].zero++;
            } else if (l[i] == '1') {
                frequencies[i].one++;
            }
        }
    }
    for (auto& c : frequencies) {
        if (c.zero > c.one) {
            gamma.push_back('0');
            epsilon.push_back('1');
        } else {
            gamma.push_back('1');
            epsilon.push_back('0');
        }
    }
    int index = 0;
    fmt::print("gamma size: {}\n", gamma.size());
    fmt::print("epsilon size: {}\n", epsilon.size());

    fmt::print("{}\n", gamma[11]);
    for (int i = gamma.size()-1; i >= 0; --i) {
        fmt::print("{}\n", i);
        if (gamma[i] == '1') {
            g += pow(2, index);
        }
        if (epsilon[i] == '1') {
            e += pow(2, index);
        }
        index++;
    }
    fmt::print("g: {}\n", g);
    fmt::print("e: {}\n",e);
    fmt::print("power consumption: {}\n", g * e);
}
string DayThree::makeCO2Rating() {
    std::list<string> input;
    for (auto& l : rawInput) {
        input.push_back(l);
    }
    int idx = 0;
    while (input.size() > 1 && idx < rawInput[0].size()) {
        char mC = mostCommonVert(idx, '1', input);
        for (auto it = input.begin(); it != input.end();) {
            string temp = *it;
            if (temp[idx] == mC){
                it = input.erase(it);
            } else {
                it++;
            }
        }
        idx++;
    }
    return input.front();
}

string DayThree::makeOxygenRating() {
    std::list<string> input;
    for (auto& i : rawInput) {
        input.push_back(i);
    }
    int idx = 0;

    while (input.size() > 1 && idx < rawInput[0].size()) {
        char mC = mostCommonVert(idx, '1', input);
        for (auto it = input.begin(); it != input.end();) {
            string temp = *it;
            if (temp[idx] != mC) {
                it = input.erase(it);
            } else {
                ++it;
            }
        }
        idx++;
    }
    return input.front();
}
int stringToBinary(string s) {
    int result = 0;
    int index = 0;
    for (int i = s.size()-1; i >= 0; --i) {
        if (s[i] == '1') {
            result += pow(2, index);
        }
        index++;
    }
    return result;
}
char DayThree::mostCommonVert(uint32_t idx, char favor, const std::list<string>& input) {
    int ones = 0, zeroes = 0;
    for (auto it = input.begin(); it != input.end();) {
        string temp = *it;
        if (temp[idx] == '1') {
            ones++;
        } else if (temp[idx] == '0') {
            zeroes++;
        }
        ++it;
    }
    if (ones == zeroes) {
        return favor;
    }
    if (ones > zeroes) {
        return '1';
    } else {
        return '0';
    }
}
void printList(std::list<string> l) {
    for (auto it = l.begin(); it != l.end();) {
        fmt::print("{}->", *it);
        ++it;
    }
    fmt::print("\n");
}


