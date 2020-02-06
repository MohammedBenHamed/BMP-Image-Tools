#include "PixelData.h"
PixelData::PixelData(int xSize, int ySize)
{

    if (xSize<=0 || ySize<=0)
    {
        throw InvalidCoordinate();
    }
    this->xSize = xSize;
    this->ySize = ySize;
}
Pixel& PixelData::getPixel(int x, int y)
{

    if (!correctSize()) throw IncompletePixelMap();
    if (x>=xSize || y>=ySize || x<0 || y<0)
    {
        throw InvalidCoordinate();
    }
    return PixelMap.at(x+y*xSize);
}
void PixelData::addPixel(int red, int green, int blue)
{
    PixelMap.push_back(Pixel(red,green,blue));
}
bool PixelData::correctSize()
{
    return ((int)PixelMap.size() == xSize * ySize);
}
