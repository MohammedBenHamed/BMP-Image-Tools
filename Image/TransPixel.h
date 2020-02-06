#ifndef TRANSPIXEL_H
#define TRANSPIXEL_H

#include "Pixel.h"

class TransPixel : public Pixel
{
    private:
    char transparency; // Represents transparency where 0 is fully opaque and 255 is fully transparent
    public:
    TransPixel(int red, int green, int blue, int transparency);
    void setTransparency(char transparency);
    char getTransparency();
    void printPixel(); // debug


};

#endif // TRANSPIXEL_H
