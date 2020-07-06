#include "ImageFile.h"
namespace ImageFile
{


    namespace
    {
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
    }

    namespace getInfo
    {
        unsigned int xSize(std::string filename)
        {
            std::string content = File::openFile(filename);
            std::string x_str;
            for (int i = 0; i < 4 ; i++)
            {
                x_str+=(char)content[0x12+i];
            } // Set up the strings to read the Little Endian values from.
            return readLittleEndian(x_str);
        }
        unsigned int ySize(std::string filename)
        {
            std::string content = File::openFile(filename);
            std::string y_str;
            for (int i = 0; i < 4 ; i++)
            {
                y_str+=(char)content[0x16+i];
            } // Set up the strings to read the Little Endian values from.
            return readLittleEndian(y_str);
        }
    }

}


