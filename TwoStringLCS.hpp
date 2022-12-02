/***************************************************************
  Student Name: Collin Lowing
  File Name: TwoStringLCS.hpp
  Project 5

  generates an LCS of two strings
***************************************************************/

#ifndef COP4534_P5_TWOSTRINGLCS_HPP
#define COP4534_P5_TWOSTRINGLCS_HPP

#include <cstring>
#include <iostream>
#include <string>

class TwoStringLCS {
private:
    int **stringCombination;
    const char *stringX;
    const char *stringY;
    int m;
    int n;
    int lengthOfSubstring = 0;
public:
    TwoStringLCS(const char *stringX, const char *stringY, int m, int n);

    void printLCS(int i, int j);

    void generateCombinationString();

    int **getStringCombination() const;

    const char *getStringX() const;

    const char *getStringY() const;

    void print();

    int getLengthOfSubstring() const;

    ~TwoStringLCS();
};


#endif //COP4534_P5_TWOSTRINGLCS_HPP
