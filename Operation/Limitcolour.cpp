#include "Operation.h"
namespace Operation
{
    void limitColour(Img& image, int powerOfTwo)
    {
        //TODO: Perform checks on powerofTwo, make sure it can only be 1 to 7
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        uint8_t shades = pow(2,powerOfTwo); //Determines how many grey shades are available
        uint8_t check = 256/(shades); // Value used to compare RGB grey level
        uint8_t valueIncrement = 256/(shades-1); // Value used to set Pixel value
        // --- EXAMPLE ---
        // If the user inputs a value of 1 for the powerOfTwo variable, there will be 2 shades
        // The program will check if each RGB grey value is lower than 128.
        // If the value is lower than 128, then it will be set to 0. Otherwise, it will be set to 255
        uint8_t r,g,b;

        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                r = 255; g = 255; b = 255; // default value for red, green and blue elements
                for (int i = 1; i<shades; i++)
                {
                    if (image.getPixel(x_,y_).r < check*i)
                    {
                        r = valueIncrement*(i-1);
                        i = shades; // End loop
                    }
                }
                for (int i = 1; i<shades; i++)
                {
                    if (image.getPixel(x_,y_).g < check*i)
                    {
                        g = valueIncrement*(i-1);
                        i = shades; // End loop
                    }
                }
                for (int i = 1; i<shades; i++)
                {
                    if (image.getPixel(x_,y_).b < check*i)
                    {
                        b = valueIncrement*(i-1);
                        i = shades; // End loop
                    }
                }
                image.setPixel(x_,y_,Pixel(r,g,b,image.getPixel(x_,y_).a));
            }
        }
    }
}
