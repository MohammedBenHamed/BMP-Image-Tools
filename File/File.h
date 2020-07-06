#ifndef FILE_H
#define FILE_H
#include "../Exception/InvalidFile.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

namespace File
{
    std::string openFile(std::string filename);
    void writeFile(std::string filename, std::string content);
    bool isValid(std::string filename); // Quick way to check if file exists or not

}


#endif//FILE_H
