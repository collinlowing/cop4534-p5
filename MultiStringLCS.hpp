//
// Created by cel on 11/18/22.
//

#ifndef COP4534_P5_MULTISTRINGLCS_HPP
#define COP4534_P5_MULTISTRINGLCS_HPP

#include <iostream>

class MultiStringLCS {
private:
    char** similarityTable;
    const char** stringTable;
    int* stringLengths;
    int numberOfStrings;
    int lengthOfLCS = 0;
    int** stringCombination;
    int MAX_LENGTH = 64; // expected maximum length of any string
public:

    MultiStringLCS(const std::vector<std::string>& strings);
    char getSimilarity(int stringIndex1, int stringIndex2);
    void printSimilarityTable();
    void generateCombinationString(int index1, int index2);
    void getLCS(int index1, int index2, int i, int j);
    void fillSimilarityTable();
    ~MultiStringLCS();
};


#endif //COP4534_P5_MULTISTRINGLCS_HPP
