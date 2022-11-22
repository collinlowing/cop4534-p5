#include <iostream>
#include "FileParser.hpp"
#include "TwoStringLCS.hpp"

int main() {
    std::vector<std::string> fileStrings = FileParser::getItemsFromFile("twoStrings.txt");

    std::string stringX = fileStrings[0];
    std::string stringY = fileStrings[1];
    int m = stringX.size();
    int n = stringY.size();
    TwoStringLCS ts(stringX.c_str(), stringY.c_str(), m, n);

    ts.generateCombinationString();
    ts.printLCS(m, n);

    return 0;
}
