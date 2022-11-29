//
// Created by cel on 11/28/22.
//

#include "gtest/gtest.h"
#include "../MultiStringLCS.hpp"

TEST(MultiStringTests, getStringTable) {
    std::string fileName = "multiStringsTest.txt";
    MultiStringLCS ms(fileStrings);
    ms.fillSimilarityTable();
    ms.printSimilarityTable();
}
