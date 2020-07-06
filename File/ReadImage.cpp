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
        namespace getPosition
        {
            int BMP24(int x, int y, int xSize, int ySize, int colour)
            {
                int zeros = xSize%4;
                return 3*x + (ySize-(y+1))*(zeros+3*xSize) + colour;
            }
        }
    }

    Img Read(std::string filename)
    {
        //TODO: Make checks for invalid file names
        //TODO: Be able to read other image file types
        std::string content = File::openFile(filename);
        std::string x_str, y_str;
        for (int i = 0; i < 4 ; i++)
        {
            x_str+=(char)content[0x12+i];
            y_str+=(char)content[0x16+i];
        } // Set up the strings to read the Little Endian values from.
        int x = readLittleEndian(x_str);
        int y = readLittleEndian(y_str);
        content = content.substr(0x36,content.size()); // Remove header to only include bitmap
        std::vector<Pixel> pixelmap;
        uint8_t r_, g_, b_;
        for (int y_ = 0; y_<y; y_++)
        {
            for (int x_ = 0; x_<x; x_++)
            {
                r_ = content.at(getPosition::BMP24(x_,y_,x,y,2));
                g_ = content.at(getPosition::BMP24(x_,y_,x,y,1));
                b_ = content.at(getPosition::BMP24(x_,y_,x,y,0));
                pixelmap.push_back(Pixel(r_,g_,b_));
            }
        }

        return Img(x,y,pixelmap);
    }



}
