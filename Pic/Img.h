#ifndef IMG_H
#define IMG_H
#include "Pixel.h"
#include "../Exception/IncompletePixelMap.h"
#include "../Exception/InvalidCoordinate.h"
#include <vector>
using PixelMap = std::vector<Pixel>;
class Img
{
    private:
    unsigned int xSize, ySize;
    PixelMap pixelmap;
    public:
    Img(unsigned int xSize, const unsigned int ySize, Pixel p);
    Img(unsigned int xSize, const unsigned int ySize, PixelMap pixelmap);
    Pixel getPixel(unsigned int x, unsigned int y) const;
    void setPixel(unsigned int x, unsigned y, Pixel pixel);
    unsigned int getXSize() const;
    unsigned int getYSize() const;
};

std::ostream& operator<< (std::ostream &out, const Img &img);

#endif // IMG_H
