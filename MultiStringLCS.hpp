//
// Created by cel on 11/18/22.
//

#ifndef COP4534_P5_MULTISTRINGLCS_HPP
#define COP4534_P5_MULTISTRINGLCS_HPP

#include <iostream>

class MultiStringLCS {
private:
    char** similarityTable;
    char** stringTable;
    int* stringLengths;
    int numberOfStrings;
public:
    char getSimilarity(char* stringX, char* stringY);
    void printSimilarityTable();
};


#endif //COP4534_P5_MULTISTRINGLCS_HPP
