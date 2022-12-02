/***************************************************************
  Student Name: Collin Lowing
  File Name: main.cpp
  Project 5

  driving function that runs methods from other classes
***************************************************************/

#include <iostream>
#include "FileParser.hpp"
#include "TwoStringLCS.hpp"
#include "MultiStringLCS.hpp"

int main() {
    // get file for two strings
    std::vector<std::string> twoStringsFile = FileParser::getItemsFromFile("twoStrings.txt");

    // get both strings
    std::string stringX = twoStringsFile[0];
    std::string stringY = twoStringsFile[1];

    // get string lengths + 1
    int m = stringX.size() + 1;
    int n = stringY.size() + 1;

    // convert to c strings
    const char *cStringX = stringX.c_str();
    const char *cStringY = stringY.c_str();

    TwoStringLCS ts(cStringX, cStringY, m, n);

    ts.generateCombinationString();
    ts.printLCS(m - 1, n - 1); // subtract 1 for actual string lengths

    std::cout << std::endl << "Length of LCS: " << ts.getLengthOfSubstring() << std::endl;

    // get multi string file
    std::vector<std::string> multiStringsFile = FileParser::getItemsFromFile("multiStrings.txt");

    MultiStringLCS ms(multiStringsFile);
    ms.fillSimilarityTable();
    ms.printSimilarityTable();

    return 0;
}
