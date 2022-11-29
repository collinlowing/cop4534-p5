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
public:

    MultiStringLCS(const std::vector<std::string>& strings);
    char getSimilarity(int stringIndex1, int stringIndex2);
    void printSimilarityTable();
    int getLCS(int stringIndex1, int stringIndex2);
    void fillSimilarityTable();
    ~MultiStringLCS();
    int getNumberOfStrings() const;
    int *getStringLengths() const;
    const char **getStringTable() const;
    char **getSimilarityTable() const;
};


#endif //COP4534_P5_MULTISTRINGLCS_HPP
