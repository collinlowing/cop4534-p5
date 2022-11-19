
#include "gtest/gtest.h"
#include "../FileParser.hpp"
#include <vector>

TEST(ParserTest, GetItems) {
    std::vector<std::string> fileStrings = FileParser::getItemsFromFile("testTwoStrings.txt");

    ASSERT_TRUE(fileStrings.size() > 0);

    std::vector<std::string> strings = {
        "asdfgh",
        "qwerewtdsfdsfa"
    };

    for(int i = 0; i < fileStrings.size(); i++) {
        EXPECT_EQ(fileStrings[i], strings[i]);
    }
}