#include "File.h"
namespace File
{
    std::string openFile(std::string filename)
    {
        std::ifstream file(filename,std::ios::binary);
        std::stringstream buffer; // Initialise buffer
        buffer << file.rdbuf(); // Buffer the file content
        std::string content = buffer.str();
        return content;
    }
    Img openImage(std::string filename)
    {
        std::string content = openFile(filename);
        std::string x_str, y_str;
        uint8_t r_, g_, b_;
        for (int i = 0; i < 4 ; i++)
        {
            x_str+=(char)content[0x12+i];
            y_str+=(char)content[0x16+i];
        } // Set up the strings to read the Little Endian values from.
        int x = Tool::readLittleEndian(x_str);
        int y = Tool::readLittleEndian(y_str);
        content = content.substr(0x36,content.size());
        Img newImage(x,y);
        for (int y_ = 0; y_<y; y_++)
        {

            for (int x_ = 0; x_<x; x_++)
            {
                r_ = content.at(Tool::BMP24::getPosition(x_,y_,x,y,2));
                g_ = content.at(Tool::BMP24::getPosition(x_,y_,x,y,1));
                b_ = content.at(Tool::BMP24::getPosition(x_,y_,x,y,0));
                newImage.addPixel(Pixel(r_,g_,b_));
            }
        }
        return newImage;

    }
    namespace WriteAs
    {
        void BMP24(Img& image, std::string filename)
        {
            std::ofstream file;
            std::string output;
            int x = image.getXSize();
            int y = image.getYSize();
            int zeros = x%4; // Amount of zeros that are written to file after each x-line of the image.
            int sizeOfFile = 0x36 + x*y*3 + zeros * y;
            output+= "BM"; // Signature
            output+=Tool::littleEndian(sizeOfFile,4);
            output+=Tool::littleEndian(0,4); // Unused
            output+=Tool::littleEndian(0x36,4); // Size of whole header
            //Info Header
            output+=Tool::littleEndian(0x28,4); // Size of info header
            output+=Tool::littleEndian(x,4); // x size
            output+=Tool::littleEndian(y,4); // y size
            output+=Tool::littleEndian(1,2); // Number of planes (always one)
            output+=Tool::littleEndian(24,2); // Bits per pixel (e.g. 24-bit)
            output+=Tool::littleEndian(0,4); // Type of Compression, 0 = none
            output+=Tool::littleEndian(sizeOfFile-0x36,4); // Size of Compression, i.e. the length of pixel data
            output+=Tool::littleEndian(0,4); // Unused
            output+=Tool::littleEndian(0,4); // Unused
            output+=Tool::littleEndian(0,4); // Unused
            output+=Tool::littleEndian(0,4); // Unused
            for (int y_ = y-1; y_>-1; y_--)
            {
                for (int x_ = 0; x_<x; x_++)
                {
                    output+=image.getPixel(x_,y_).b;
                    output+=image.getPixel(x_,y_).g;
                    output+=image.getPixel(x_,y_).r;
                }
                for (int z = 0; z<zeros; z++)
                {
                    output += (char)0x00;
                }
            }
            file.open(filename,std::ios::binary);
            file << output;
        }

    }


}
