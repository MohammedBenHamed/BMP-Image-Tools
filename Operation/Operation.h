#ifndef OPERATION_H
#define OPERATION_H
#include "../Pic/Img.h"
namespace Operation
{
    void monochrome(Img& image);
    void changeColour(Img& image, std::vector<Pixel> pList, Pixel p);
    void changeColourIfNot(Img& image, std::vector<Pixel> pList, Pixel p);
    void limitColour(Img& image, int powerOfTwo);
    void crop(Img& image, int xSize, int ySize, int xBegin, int yBegin);
    void cropEdges(Img& image, Pixel p);
    void addImageTo(Img& image1, Img& image2, int xBegin, int yBegin, Pixel p);
    void addBorder(Img& image, Pixel p1, Pixel p2);
    void addInnerBorder(Img& image, Pixel p1, Pixel p2, Pixel pBck);
    void colourise(Img& image, Pixel p);
    void getColours(Img& image, std::string filename);
}
#endif//OPERATION_H
