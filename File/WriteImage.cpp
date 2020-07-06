#include "ImageFile.h"
namespace ImageFile
{
    namespace
    {
        std::string writeLittleEndian(unsigned number, unsigned numOfBytes) // Max 4
        {
            std::vector<char> bytePos;
            for (unsigned int i = 1; i<numOfBytes+1; i++)
            {
                int byte;
                int divisor;
                divisor = std::pow(0x100,i-1);
                byte = (number/divisor)%256;
                bytePos.push_back((char)byte);
            }
            std::string output(bytePos.begin(), bytePos.end());
            return output;
        }
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
                output+=writeLittleEndian(sizeOfFile,4);
                output+=writeLittleEndian(0,4); // Unused
                output+=writeLittleEndian(0x36,4); // Size of whole header
                //Info Header
                output+=writeLittleEndian(0x28,4); // Size of info header
                output+=writeLittleEndian(x,4); // x size
                output+=writeLittleEndian(y,4); // y size
                output+=writeLittleEndian(1,2); // Number of planes (always one)
                output+=writeLittleEndian(24,2); // Bits per pixel (e.g. 24-bit)
                output+=writeLittleEndian(0,4); // Type of Compression, 0 = none
                output+=writeLittleEndian(sizeOfFile-0x36,4); // Size of Compression, i.e. the length of pixel data
                output+=writeLittleEndian(0,4); // Unused
                output+=writeLittleEndian(0,4); // Unused
                output+=writeLittleEndian(0,4); // Unused
                output+=writeLittleEndian(0,4); // Unused
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
                File::writeFile(filename,output);

            }
            // TODO: To be able to write files with 32-bit images (including alpha)
        }
}
