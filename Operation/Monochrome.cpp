#include "Operation.h"
namespace Operation
{
    void monochrome(Img& image)
    {
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                short grey = (image.getPixel(x_,y_).r + image.getPixel(x_,y_).g + image.getPixel(x_,y_).b)/3;
                // Calculate grey value from taking average of RGB values.
                image.setPixel(x_,y_,Pixel(uint8_t(grey),uint8_t(grey),uint8_t(grey),image.getPixel(x_,y_).a));
                // Apply grey value to pixel, keep alpha value the same
            }
        }
    }
}

