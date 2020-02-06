#include "TransPixel.h"
TransPixel::TransPixel(int red, int green, int blue, int transparency) : Pixel(red,green,blue)
{
    setRed((char)red);
    setGreen((char)green);
    setBlue((char)blue);
    this->transparency = transparency;
}

void TransPixel::setTransparency(char transparency)
{
    this->transparency = transparency;
}

char TransPixel::getTransparency()
{
    return transparency;
}

void TransPixel::printPixel()
{
    std::cout << Tool::charToInt(getRed()) << " " << Tool::charToInt(getGreen()) << " " << Tool::charToInt(getBlue());
    std::cout << " " << Tool::charToInt(getTransparency()) << "\n";
}
