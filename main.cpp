#include <iostream>
#include "FileParser.hpp"
#include "TwoStringLCS.hpp"
#include "MultiStringLCS.hpp"

int main() {
    std::vector<std::string> twoStringsFile = FileParser::getItemsFromFile("twoStrings.txt");

    std::string stringX = twoStringsFile[0];
    std::string stringY = twoStringsFile[1];
    int m = stringX.size() + 1;
    int n = stringY.size() + 1;
    TwoStringLCS ts(stringX.c_str(), stringY.c_str(), m, n);

    ts.generateCombinationString();
    ts.printLCS(m - 1, n - 1);
    std::cout << std::endl << "Length of LCS: " << ts.getLengthOfSubstring() << std::endl;

    std::vector<std::string> multiStringsFile = FileParser::getItemsFromFile("multiStrings.txt");

    MultiStringLCS ms(multiStringsFile);
    ms.fillSimilarityTable();
    ms.printSimilarityTable();

    return 0;
}
