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

char MultiStringLCS::getSimilarity(int stringIndex1, int stringIndex2) {
    // declare and initialize variables
    int smallestLength;
    int largestLength;
    int lengthLCS = 0;
    char similarityLabel;

    // get sizes of strings
    int lengthOfString1 = stringLengths[stringIndex1];
    int lengthOfString2 = stringLengths[stringIndex2];

    // get smallest length
    if(lengthOfString1 <= lengthOfString2) {
        smallestLength = lengthOfString1;
        largestLength = lengthOfString2;
    }
    else {
        smallestLength = stringIndex2;
        largestLength = stringIndex1;
    }

    // get LCS for two strings
    lengthLCS = getLCS(stringIndex1, stringIndex2);

    double sizePercentage = (double) smallestLength/largestLength;
    double lcsPercentage = (double) lengthLCS/smallestLength;

    // get similarity labels
    // high similarity if 10% of length and 90% of smallest length and LCS length
    if(sizePercentage <= .10 && lcsPercentage >= .90) {
        similarityLabel = 'H';
    }
    // low similarity if 20% of length and 80% of smallest length and LCS length
    else if(sizePercentage <= .20 && lcsPercentage >= .80) {
        similarityLabel = 'M';
    }
    // low similarity if 40% of length and 50% of smallest length and LCS length
    else if(sizePercentage <= .40 && lcsPercentage >= .50) {
        similarityLabel = 'L';
    }
    // otherwise dissimilar
    else {
        similarityLabel = 'D';
    }

    // set label to table
    similarityTable[stringIndex1][stringIndex2] = similarityLabel;

    return similarityLabel;
}

void MultiStringLCS::printSimilarityTable() {
    for(int i = 1; i <= numberOfStrings; i++) {
        if(i == 1) {
            std::cout << "\t";
        }
        if(i <= 9) {
            std::cout << "0" << i << "\t";
        }
        else { // greater than 9 so do not add 0 to beginning
            std::cout << i << "\t";
        }
    }

    std::cout << std::endl;

    for(int m = 1; m <= numberOfStrings; m++) {
        if(m <= 9) {
            std::cout << "0" << m << "\t";
        }
        else { // greater than 9 so do not add 0 to beginning
            std::cout << m << "\t";
        }
        for(int n = 1; n <= numberOfStrings; n++) {
            std::cout << similarityTable[m-1][n-1] << "\t";
        }
        std::cout << std::endl;
    }
}

int MultiStringLCS::getLCS(int stringIndex1, int stringIndex2) {
    return 0;
}

void MultiStringLCS::fillSimilarityTable() {
    int counter = 0;
    for(int i = 0; i < numberOfStrings; i++) {
        for(int j = 0; j < numberOfStrings; j++) {
            if(j <= counter) {
                similarityTable[i][j] = '-';
            }
            else {
                getSimilarity(i, j);
            }
        }
        counter++;
    }
}

MultiStringLCS::~MultiStringLCS() {
    for(int i = 0; i < numberOfStrings; i++) {
        delete similarityTable[i];
    }
    delete[] similarityTable;

/*
    for(int i = 0; i < numberOfStrings; i++) {
        delete stringTable[i];
    }
*/
    delete[] stringTable;

    delete [] stringLengths;
}

char **MultiStringLCS::getSimilarityTable() const {
    return similarityTable;
}

const char **MultiStringLCS::getStringTable() const {
    return stringTable;
}

int *MultiStringLCS::getStringLengths() const {
    return stringLengths;
}

int MultiStringLCS::getNumberOfStrings() const {
    return numberOfStrings;
}

