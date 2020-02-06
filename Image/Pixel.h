#ifndef PIXEL_H
#define PIXEL_H
#include "../Functions/Tool.h"
#include "../Exception/InvalidByte.h"
#include <iostream>

class Pixel
{
    private:
    char red, green, blue; // Variables that represent each colour element of pixel
    public:
    Pixel(int red, int green, int blue);
    void greyPixel(); // Change the colour of the pixel into grey
    void printPixel(); // debug
    int getRed();
    void setRed(int red);
    int getGreen();
    void setGreen(int green);
    int getBlue();
    void setBlue(int blue);


};
#endif // PIXEL_H
