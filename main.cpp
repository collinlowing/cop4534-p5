#include <iostream>
#include "FileParser.hpp"
#include "TwoStringLCS.hpp"

int main() {
    std::vector<std::string> fileStrings = FileParser::getItemsFromFile("twoStrings.txt");

    std::string stringX = fileStrings[0];
    std::string stringY = fileStrings[1];
    int m = stringX.size() + 1;
    int n = stringY.size() + 1;
    TwoStringLCS ts(stringX.c_str(), stringY.c_str(), m, n);

    ts.generateCombinationString();
    ts.printLCS(m - 1, n - 1);

    return 0;
}
