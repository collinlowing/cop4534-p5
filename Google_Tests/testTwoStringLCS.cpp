
#include "gtest/gtest.h"
#include "../TwoStringLCS.hpp"

TEST(TwoStringTests, initializeStrings) {
    std::string stringX = "asdfgh";
    std::string stringY = "qwewrasd";
    int m = stringX.size();
    int n = stringY.size();
    TwoStringLCS ts(stringX.c_str(), stringY.c_str(), m, n);

    // get strings
    const char* x = ts.getStringX();
    const char* y = ts.getStringY();

    // make sure they are not null
    ASSERT_TRUE(x != nullptr);
    ASSERT_TRUE(y != nullptr);

    // check strings
    for(int i = 0; i < m; i++) {
        EXPECT_EQ(x[i], stringX[i]);
    }
    for(int i = 0; i < n; i++) {
        EXPECT_EQ(y[i], stringY[i]);
    }
}

TEST(TwoStringTests, generateCombinationString) {
    std::string stringX = "qwewrasd";
    std::string stringY = "asdfgh";
    int m = stringX.size() + 1;
    int n = stringY.size() + 1;
    int** combination = nullptr;
    TwoStringLCS ts(stringX.c_str(), stringY.c_str(), m, n);

    ts.generateCombinationString();
    combination = ts.getStringCombination();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << combination[i][j] << " ";
        }
        std::cout << std::endl;
    }

    ts.printLCS(m-1, n-1);



    ASSERT_TRUE(!(combination == nullptr));

    //EXPECT_EQ(combination[m-2][n-2], 0);

}