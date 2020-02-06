#ifndef IMG_H
#define IMG_H
#include "Pixel.h"
#include "../Exception/InvalidCoordinate.h"
#include "../Exception/IncompletePixelMap.h"
//#include "../Exception/InvalidByte.h"
#include <vector>
using PixelMap = std::vector<Pixel>;
class Img
{
    private:
    int xSize, ySize;
    PixelMap pixelmap;
    public:
    Img(int xSize, int ySize);
    Pixel& getPixel(int x, int y);
    void addPixel(Pixel p);
    void changePixel(int x, int y, Pixel p);
    bool correctSize();
    bool isEmpty();
    int getXSize();
    int getYSize();
    void setXSize(int xSize);
    void setYSize(int ySize);
    PixelMap& getPixelMap();
    void setPixelMap(PixelMap pixelmap);
};
#endif // IMG_H
