//
// Created by cel on 11/18/22.
//

#include <vector>
#include "MultiStringLCS.hpp"

MultiStringLCS::MultiStringLCS(const std::vector<std::string>& strings) {
    // get the number of strings
    numberOfStrings = std::stoi(strings[0]);

    // initialize similarityTable
    similarityTable = new char*[numberOfStrings];
    for(int i = 0; i < numberOfStrings; i++) {
        similarityTable[i] = new char[numberOfStrings];
    }

    // initialize stringTable
    stringTable = new const char*[numberOfStrings];
    for(int i = 0; i < numberOfStrings; i++) {
        stringTable[i] = new char[numberOfStrings];
    }

    // initialize stringLengths
    stringLengths = new int[numberOfStrings];

    // copy strings to class attributes
    for(int i = 0; i < numberOfStrings; i++) {
        stringLengths[i] = strings[i+1].size();
        stringTable[i] = strings[i+1].c_str();
    }
}

char MultiStringLCS::getSimilarity(char *stringX, char *stringY) {
    return 0;
}

void MultiStringLCS::printSimilarityTable() {
    for(int i = 0; i < numberOfStrings; i++) {
        if(i <= 9) {
            std::cout << "0" << i << " ";
        }
        else { // greater than 9 so do not add 0 to beginning
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    for(int m = 0; m < numberOfStrings; m++) {
        if(m <= 9) {
            std::cout << "0" << m << " ";
        }
        else { // greater than 9 so do not add 0 to beginning
            std::cout << m << " ";
        }
        for(int n = 0; n < numberOfStrings; n++) {
            std::cout << similarityTable[m][n] << " ";
        }
        std::cout << std::endl;
    }
}

MultiStringLCS::~MultiStringLCS() {
    for(int i = 0; i < numberOfStrings; i++) {
        delete similarityTable[i];
    }
    delete[] similarityTable;

    for(int i = 0; i < numberOfStrings; i++) {
        delete stringTable[i];
    }
    delete[] stringTable;

    delete [] stringLengths;
}


