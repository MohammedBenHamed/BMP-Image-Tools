#include "Operation.h"
namespace Operation
{
    void changeColour(Img& image, std::vector<Pixel> pList, Pixel p)
    {
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                for (Pixel p_item: pList)
                {
                    if (image.getPixel(x_,y_) ==p_item) image.setPixel(x_,y_,p);
                    // Scan through the list of pixels to see if there is an equal pixel
                }

            }
        }
    }
    void changeColourIfNot(Img& image, std::vector<Pixel> pList, Pixel p)
    {
        bool unique = 1;
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                for (Pixel p_item: pList)
                {
                    if (image.getPixel(x_,y_) ==p_item) unique = 0; // Compare the current pixel with the pixels in list
                    // If the current pixel is equal to any pixels in the list, mark it as not unique
                }
                if (unique) image.setPixel(x_,y_,p); // only change pixel if it does not match any pixels in list
                unique = 1; // reset value for next loop

            }
        }

    }
}

