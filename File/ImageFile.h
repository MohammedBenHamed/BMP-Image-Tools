#ifndef IMAGEFILE_H
#define IMAGEFILE_H
#include "../Pic/Img.h"
#include "File.h"

namespace ImageFile
{
    Img Read(std::string filename);
    namespace WriteAs
    {
        void BMP24(Img& image, std::string filename);
    }
    namespace getInfo // Done to quickly get information about an image without storing it as an Img object
    {
        unsigned int xSize(std::string filename);
        unsigned int ySize(std::string filename);
    }
}


#endif//IMAGEFILE_H
