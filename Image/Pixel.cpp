#include "Pixel.h"

Pixel::Pixel(int red, int green, int blue)
{
    if (red>255 || red<0 ||
        green>255 || green<0 ||
        blue>255 || blue<0 )
        {
            throw InvalidByte();
        }
    this->red = (char)red;
    this->green = (char)green;
    this->blue = (char)blue;
}
void Pixel::greyPixel()
{
    int grey =  Tool::charToInt(red) +  Tool::charToInt(green) +  Tool::charToInt(blue);
    grey = grey/3; // Obtain grey value
    std::cout << grey << "?\n";
    setRed(grey);
    setGreen(grey);
    setBlue(grey); // Apply grey value to the three colours
}

void Pixel::printPixel()
{
    std::cout << Tool::charToInt(red) << " " << Tool::charToInt(green) << " " << Tool::charToInt(blue) << "\n";
}

int Pixel::getRed()
{
    return Tool::charToInt(red);
}
void Pixel::setRed(int red)
{
    if (red>255 || red<0)
    {
        throw InvalidByte();
    }
    this->red = (char)red;
}
int Pixel::getGreen()
{
    return Tool::charToInt(green);
}
void Pixel::setGreen(int green)
{
    if (green>255 || green<0)
    {
        throw InvalidByte();
    }
    this->green = (char)green;
}
int Pixel::getBlue()
{
    return Tool::charToInt(blue);
}
void Pixel::setBlue(int blue)
{
    if (blue>255 || blue<0)
    {
        throw InvalidByte();
    }
    this->blue = (char)blue;
}
