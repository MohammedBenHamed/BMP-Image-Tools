#ifndef TOOL_H
#define TOOL_H
#include <iostream>
#include <vector>
namespace Tool
{
    std::string littleEndian(int number, int numOfBytes); // Max 4
    int pow(int number, int index);
    unsigned int readLittleEndian(std::string input);

    namespace BMP24
    {
        int getPosition(int x, int y, int xSize, int ySize, int colour);
    }
}
#endif//TOOL_H
