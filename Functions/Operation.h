#ifndef OPERATION_H
#define OPERATION_H
#include "../Pic/Img.h"
#include "../Functions/Tool.h"
#include <iostream>
#include <vector>
namespace Operation
{
    void monochrome(Img& image);
    void fill(Img& image, Pixel p);
    void changeColour(Img& image, Pixel p1, Pixel p2);
    void changeColour(Img& image, std::vector<Pixel> pList, Pixel p);
    void changeColourIfNot(Img& image, Pixel p1, Pixel p2);
    void changeColourIfNot(Img& image, std::vector<Pixel> pList, Pixel p);
    void limitColour(Img& image, int powerOfTwo);
    void crop(Img& image, int xSize, int ySize, int xBegin, int yBegin);
    void cropEdges(Img& image, Pixel p);
}
#endif//OPERATION_H

