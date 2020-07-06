#include "Operation.h"
namespace Operation
{
    void crop(Img& image, int xSize, int ySize, int xBegin, int yBegin)
    {
        std::vector<Pixel> pixelmap;
        for (int y = 0; y<ySize; y++)
        {
            for (int x = 0; x<xSize; x++)
            {
                pixelmap.push_back(image.getPixel(x+xBegin,y+yBegin));
            }
        }
        image = Img(xSize,ySize,pixelmap);


    }
    void cropEdges(Img& image, Pixel p)
    {
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        int top = 0, bottom = ySize-1,  left = 0, right = xSize-1;
        // STEP 1: Check which upper y coordinate is the first non-empty
        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                if (!(image.getPixel(x_,y_) == p))
                {
                    x_ = xSize; y_ = ySize; // Take loop to the end
                }
            }
            if (y_<ySize)top++; // Don't increment if search has been halted
        }
        // STEP 2: Check which lower y coordinate is the first non-empty
        for (int y_ = ySize-1; y_>-1; y_--)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                if (!(image.getPixel(x_,y_) == p))
                {
                    x_ = xSize; y_ = -1; // Take loop to the end
                }
            }
            if (y_>-1)bottom--; // Don't increment if search has been halted
        }
        // STEP 3: Check which left x coordinate is the first non-empty
        for (int x_ = 0; x_ < xSize; x_++)
        {
            for (int y_ = 0; y_ < ySize; y_++)
            {
                if (!(image.getPixel(x_,y_) == p))
                {
                    x_ = xSize; y_ = ySize; // Take loop to the end
                }
            }
            if (x_<xSize)left++; // Don't increment if search has been halted
        }
        // STEP 4: Check which right x coordinate is the first non-empty
        for (int x_ = xSize-1; x_ >-1; x_--)
        {
            for (int y_ = 0; y_ < ySize; y_++)
            {
                if (!(image.getPixel(x_,y_) == p))
                {
                    x_ = -1; y_ = ySize; // Take loop to the end
                }
            }
            if (x_>-1)right--; // Don't increment if search has been halted
        }

        if (bottom != -1) // Don't crop if the image is one solid colour
        {
            crop(image,right-left+1,bottom-top+1,left,top); // Crop the image
        }

    }

}
