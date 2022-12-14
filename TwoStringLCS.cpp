/***************************************************************
  Student Name: Collin Lowing
  File Name: TwoStringLCS.cpp
  Project 5

  generates an LCS of two strings
***************************************************************/

#include "TwoStringLCS.hpp"

TwoStringLCS::TwoStringLCS(const char *stringX, const char *stringY, int m, int n) {
    // copy strings to class attributes
    this->stringX = stringX;
    this->stringY = stringY;

    this->m = m;
    this->n = n;

    // declaring array of pointers for size of stringX
    stringCombination = new int *[m];

    for (int i = 0; i < m; i++) {
        // declaring memory for size of stringY
        stringCombination[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            stringCombination[i][j] = 0;
        }
    }
}

void TwoStringLCS::printLCS(int i, int j) {
    // stopping condition
    if (i == 0 || j == 0) {
        return;
    }
    if (stringX[i] == stringY[j]) {
        printLCS(i - 1, j - 1);
        lengthOfSubstring++;
        printf("%c", stringX[i - 1]);
    } else if (stringCombination[i - 1][j] >= stringCombination[i][j - 1]) {

        printLCS(i - 1, j);
    } else {
        printLCS(i, j - 1);
    }
}

void TwoStringLCS::generateCombinationString() {
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (stringX[i] == stringY[j]) {
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

/* used for testing
void TwoStringLCS::print() {
    // print combination
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << stringCombination[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
*/

TwoStringLCS::~TwoStringLCS() {
    for (int i = 0; i < m; i++) {
        delete stringCombination[i];
    }
    delete[] stringCombination;
}
