 #ifndef PIXELDATA_H
#define PIXELDATA_H
#include "Pixel.h"
#include "../Exception/InvalidCoordinate.h"
#include "../Exception/IncompletePixelMap.h"
#include <vector>
class PixelData
{
    private:
    std::vector<Pixel> PixelMap;
    int xSize, ySize; // Length of PixelMap
    public:
    PixelData(int xSize, int ySize);
    Pixel& getPixel(int x, int y);
    void addPixel(int red, int green, int blue);
    bool correctSize();
};
#endif // PIXELDATA_H
