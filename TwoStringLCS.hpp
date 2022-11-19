//
// Created by cel on 11/18/22.
//

#ifndef COP4534_P5_TWOSTRINGLCS_HPP
#define COP4534_P5_TWOSTRINGLCS_HPP


#include <string>

class TwoStringLCS {
private:
    char** stringCombination;
    char* stringX;
    char* stringY;
public:
    void printLCS(int i, int j);
    void generateCombinationString(std::string stringX, std::string stringY);
};


#endif //COP4534_P5_TWOSTRINGLCS_HPP
