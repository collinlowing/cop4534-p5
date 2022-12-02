/***************************************************************
  Student Name: Collin Lowing
  File Name: MultiStringLCS.cpp
  Project 5

  compares many strings with each other using LCS
***************************************************************/

#include "MultiStringLCS.hpp"

MultiStringLCS::MultiStringLCS(const std::vector<std::string> &strings) {
    // get the number of strings
    numberOfStrings = std::stoi(strings[0]);

    // initialize similarityTable
    similarityTable = new char *[numberOfStrings];
    for (int i = 0; i < numberOfStrings; i++) {
        similarityTable[i] = new char[numberOfStrings];
    }

    // initialize stringTable
    stringTable = new const char *[numberOfStrings];
    for (int i = 0; i < numberOfStrings; i++) {
        stringTable[i] = new char[numberOfStrings];
    }

    // initialize stringLengths
    stringLengths = new int[numberOfStrings];

    // copy strings to class attributes
    for (int i = 0; i < numberOfStrings; i++) {
        stringLengths[i] = strings[i + 1].size();
        stringTable[i] = strings[i + 1].c_str();
    }

    // declaring array of pointers for size of stringX
    stringCombination = new int *[MAX_LENGTH];

    for (int i = 0; i < MAX_LENGTH; i++) {
        // declaring memory for size of stringY
        stringCombination[i] = new int[MAX_LENGTH];
    }

    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            stringCombination[i][j] = 0;
        }
    }
}

char MultiStringLCS::getSimilarity(int stringIndex1, int stringIndex2) {
    // declare and initialize variables
    int smallestLength;
    int largestLength;
    char similarityLabel;

    // get sizes of strings
    int lengthOfString1 = stringLengths[stringIndex1];
    int lengthOfString2 = stringLengths[stringIndex2];

    // get smallest length
    if (lengthOfString1 <= lengthOfString2) {
        smallestLength = lengthOfString1;
        largestLength = lengthOfString2;
    } else {
        smallestLength = lengthOfString2;
        largestLength = lengthOfString1;
    }

    generateCombinationString(stringIndex1, stringIndex2);
    // get LCS for two strings
    getLCS(stringIndex1, stringIndex2, lengthOfString1, lengthOfString2);

    // calculate percentages
    // declare variables;
    double sizeDifference;
    double sizeAverage;
    double sizePercentage;
    double lcsPercentage;

    // get percent difference of the two string lengths
    sizeDifference = std::abs((double) largestLength - smallestLength);
    sizeAverage = (double) (largestLength + smallestLength) / 2.0;
    sizePercentage = sizeDifference / sizeAverage;

    // get percent difference of the lengths for the smallest string and LCS
    sizeDifference = std::abs((double) smallestLength - lengthOfLCS);
    sizeAverage = (double) (smallestLength + lengthOfLCS) / 2.0;
    lcsPercentage = 1.00 - (sizeDifference / sizeAverage); // if percent difference is 0% then it is 100% similar

    // reset LCS
    lengthOfLCS = 0;
    for (int i = 0; i < MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LENGTH; j++) {
            stringCombination[i][j] = 0;
        }
    }

    // get similarity labels
    // high similarity if 10% of length and 90% of smallest length and LCS length
    if (sizePercentage <= .10 && lcsPercentage >= .90) {
        similarityLabel = 'H';
    }
        // low similarity if 20% of length and 80% of smallest length and LCS length
    else if (sizePercentage <= .20 && lcsPercentage >= .80) {
        similarityLabel = 'M';
    }
        // low similarity if 40% of length and 50% of smallest length and LCS length
    else if (sizePercentage <= .40 && lcsPercentage >= .50) {
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
    for (int i = 1; i <= numberOfStrings; i++) {
        if (i == 1) {
            std::cout << "\t";
        }
        if (i <= 9) {
            std::cout << "0" << i << "\t";
        } else { // greater than 9 so do not add 0 to beginning
            std::cout << i << "\t";
        }
    }

    std::cout << std::endl;

    for (int i = 1; i <= numberOfStrings; i++) {
        if (i <= 9) {
            std::cout << "0" << i << "\t";
        } else { // greater than 9 so do not add 0 to beginning
            std::cout << i << "\t";
        }
        for (int j = 1; j <= numberOfStrings; j++) {
            std::cout << similarityTable[i - 1][j - 1] << "\t";
        }
        std::cout << std::endl;
    }
}

void MultiStringLCS::generateCombinationString(int index1, int index2) {
    int length1 = stringLengths[index1] + 1;
    int length2 = stringLengths[index2] + 1;
    for (int i = 1; i < length1; i++) {
        for (int j = 1; j < length2; j++) {
            if (stringTable[index1][i] == stringTable[index2][j]) {
                stringCombination[i][j] = stringCombination[i - 1][j - 1] + 1;
            } else {
                if (stringCombination[i - 1][j] >= stringCombination[i][j - 1]) {
                    stringCombination[i][j] = stringCombination[i - 1][j];
                } else {
                    stringCombination[i][j] = stringCombination[i][j - 1];
                }
            }
        }
    }
}

void MultiStringLCS::getLCS(int index1, int index2, int i, int j) {
    // stopping condition
    if (i == 0 || j == 0) {
        return;
    }
    if (stringTable[index1][i] == stringTable[index2][j]) {
        getLCS(index1, index2, i - 1, j - 1);
        lengthOfLCS++;
    } else if (stringCombination[i - 1][j] >= stringCombination[i][j - 1]) {

        getLCS(index1, index2, i - 1, j);
    } else {
        getLCS(index1, index2, i, j - 1);
    }
}

void MultiStringLCS::fillSimilarityTable() {
    int counter = 0;
    for (int i = 0; i < numberOfStrings; i++) {
        for (int j = 0; j < numberOfStrings; j++) {
            if (j <= counter) {
                similarityTable[i][j] = '-';
            } else {
                getSimilarity(i, j);
            }
        }
        counter++;
    }
}

MultiStringLCS::~MultiStringLCS() {
    for (int i = 0; i < numberOfStrings; i++) {
        delete similarityTable[i];
    }
    delete[] similarityTable;

/*  //causes a free(): invalid size error... might have to do with const char?
    for(int i = 0; i < numberOfStrings; i++) {
        delete stringTable[i];
    }
*/
    delete[] stringTable;

    for (int i = 0; i < MAX_LENGTH; i++) {
        delete stringCombination[i];
    }
    delete[] stringCombination;

    delete[] stringLengths;
}
