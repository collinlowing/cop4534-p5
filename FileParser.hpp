/***************************************************************
  Student Name: Collin Lowing
  File Name: FileParser.hpp
  Project 5

  gets strings from files
***************************************************************/

#ifndef COP4534_P3_FILEPARSER_HPP
#define COP4534_P3_FILEPARSER_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

class FileParser {
public:
    static std::vector<std::string> getItemsFromFile(std::string fileName);
};


#endif //COP4534_P3_FILEPARSER_HPP
