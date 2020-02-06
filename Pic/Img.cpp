#include "Img.h"
Img::Img(int xSize, int ySize)
{
    if (xSize<=0 || ySize<=0)
    {
        throw InvalidCoordinate();
    }
    this->xSize = xSize;
    this->ySize = ySize;
}
Pixel& Img::getPixel(int x, int y)
{
    if (!correctSize()) throw IncompletePixelMap();
    if (x>=xSize || y>=ySize || x<0 || y<0)
    {
        throw InvalidCoordinate();
    }
    return pixelmap.at(x+y*xSize);
}
void Img::addPixel(Pixel p)
{
    pixelmap.push_back(p);
}
void Img::changePixel(int x, int y, Pixel p)
{
    getPixel(x,y) = p;
}
bool Img::correctSize()
{
    return ((int)pixelmap.size() == xSize * ySize);
}
bool Img::isEmpty()
{
    return (pixelmap.size() == 0);
}
int Img::getXSize()
{
    return xSize;
}
int Img::getYSize()
{
    return ySize;
}
void Img::setXSize(int xSize)
{
    this->xSize = xSize;
}
void Img::setYSize(int ySize)
{
    this->ySize = ySize;
}
PixelMap& Img::getPixelMap()
{
    return pixelmap;
}
void Img::setPixelMap(PixelMap pixelmap)
{
    this->pixelmap = pixelmap;
}
