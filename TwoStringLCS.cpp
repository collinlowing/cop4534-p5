//
// Created by cel on 11/18/22.
//

#include "TwoStringLCS.hpp"

void TwoStringLCS::printLCS(int i, int j) {
    // stopping condition
    if(i == 0 || j == 0) {
        return;
    }
    if(stringX[i] == stringY[j]) {
        printLCS(i-1,j-1);
        printf("%c\n", stringX[i]);
    }
    else if(stringCombination[i-1][j] >= stringCombination[i][j-1]){
        printLCS(i-1, j);
    }
    else {
        printLCS(i, j-1);
    }
}

void TwoStringLCS::generateCombinationString(std::string stringX, std::string stringY) {
    int m = stringX.size();
    int n = stringY.size();
    for(int i = 1; i < m; i++) {
        stringCombination[i][0] = 0;
    }
    for(int j = 1; j < n; j++) {
        stringCombination[0][j] = 0;
    }
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(stringX.at(i) == stringY.at(j)) {
                stringCombination[i][j] = stringCombination[i-1][j-1] + 1;
            }
            else {
                if(stringCombination[i-1][j] >= stringCombination[i][j-1]) {
                    stringCombination[i][j] = stringCombination[i-1][j];
                }
                else {
                    stringCombination[i][j] = stringCombination[i][j-1];
                }
            }
        }
    }
}
