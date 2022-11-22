//
// Created by cel on 11/18/22.
//

#include "MultiStringLCS.hpp"

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
