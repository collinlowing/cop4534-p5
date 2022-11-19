
#include "FileParser.hpp"

std::vector<std::string> FileParser::getItemsFromFile(std::string fileName) {
    std::vector<std::string> values;
    int i = 0;
    std::string line;
    std::ifstream fileInputStream(fileName);

    // if fileInputStream is not opened
    if (!fileInputStream.is_open()) {
        std::cout << "fatal error: " << fileName << " could not be opened." << std::endl;
        return values;
    }

    // read lines from file
    while (std::getline(fileInputStream, line)) {
        // convert string to double value
        values.push_back(line);
        i++;
    }

    fileInputStream.close();

    return values;
}