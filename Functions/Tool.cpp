#include "Tool.h"
namespace Tool
{
    std::string littleEndian(int number, int numOfBytes) // Max 4
    {
        std::vector<char> bytePos;
        for (int i = 1; i<numOfBytes+1; i++)
        {
            int byte;
            int divisor;
            divisor = pow(0x100,i-1);
            byte = (number/divisor)%256;
            bytePos.push_back((char)byte);

        }
        std::string output(bytePos.begin(), bytePos.end());
        return output;
    }
    unsigned int readLittleEndian(std::string input)
    {
        unsigned int number = 0 ;
        for (int i = 0; i<(int)input.size(); i++)
        {
            if ( (int)input[i]<0)number+= (256+(unsigned int)input[i])*pow(256,i);
            else number+= (unsigned int)input[i]*pow(256,i);
        }
        return number;
    }
    int pow(int number, int index)
    {
        int result = number;
        for (int i = 0; i<(index-1); i++)
        {
            result *= number;
        }
        if (index == 0) result = 1;
        return result;
    }
    namespace BMP24
    {
        int getPosition(int x, int y, int xSize, int ySize, int colour)
        {
            int zeros = xSize%4;
            return 3*x + (ySize-(y+1))*(zeros+3*xSize) + colour;
        }
    }
}
