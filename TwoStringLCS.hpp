//
// Created by cel on 11/18/22.
//

#ifndef COP4534_P5_TWOSTRINGLCS_HPP
#define COP4534_P5_TWOSTRINGLCS_HPP


#include <string>

class TwoStringLCS {
private:
    int** stringCombination;
    const char* stringX;
    const char* stringY;
    int m;
    int n;
    int lengthOfSubstring = 0;
public:
    int getLengthOfSubstring() const;

public:
    TwoStringLCS(const char* stringX, const char* stringY, int m, int n);
    void printLCS(int i, int j);
    void generateCombinationString();
    int **getStringCombination() const;
    const char *getStringX() const;
    const char *getStringY() const;
    void print();
};


#endif //COP4534_P5_TWOSTRINGLCS_HPP
