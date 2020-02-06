#ifndef FILE_H
#define FILE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../Pic/Img.h"
#include "../Functions/Tool.h"
namespace File
{
    std::string openFile(std::string filename);
    Img openImage(std::string filename);
    namespace WriteAs
    {
        void BMP24(Img& image, std::string filename);
    }
}
#endif//FILE_H

