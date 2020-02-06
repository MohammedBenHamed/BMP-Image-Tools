#define __USE_MINGW_ANSI_STDIO 0 // std::to_string()
#include <iostream>
#include "Functions/Tool.h"
#include "Pic/Pixel.h"
#include "Pic/Img.h"
#include "File/File.h"
#include "Functions/Operation.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

int main()
{

    std::vector<Img> iList;
    try
    {
        iList.push_back(File::openImage("test.bmp"));
    }
    catch (const std::out_of_range& oor)
    {
        std::cout << "File could not be found. Aborting...\n";
        return -1;
    }

    Operation::cropEdges(iList.at(0),Pixel(255,255,255));
    File::WriteAs::BMP24(iList.at(0),"output.bmp");

    return 0;




}
