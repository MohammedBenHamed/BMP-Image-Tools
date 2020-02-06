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
                Pixel pixel = image.getPixel(x_,y_);
                short grey = (pixel.r + pixel.g + pixel.b)/3;
                image.getPixel(x_,y_) = Pixel(grey,grey,grey);

            }
        }
    }

    void fill(Img& image, Pixel p)
    {
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                image.getPixel(x_,y_) = p;

            }
        }
    }
    void changeColour(Img& image, Pixel p1, Pixel p2)
    {
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                if (image.getPixel(x_,y_) == p1) image.getPixel(x_,y_) = p2;
            }
        }
    }
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
                    if (image.getPixel(x_,y_) ==p_item) image.getPixel(x_,y_) = p;
                }

            }
        }
    }
    void changeColourIfNot(Img& image, Pixel p1, Pixel p2)
    {
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                if (!(image.getPixel(x_,y_) == p1)) image.getPixel(x_,y_) = p2;
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
                if (unique) image.getPixel(x_,y_) = p; // only change pixel if it does not match any pixels in list
                unique = 1; // reset value

            }
        }

    }

    void limitColour(Img& image, int powerOfTwo)
    {
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        uint8_t shades = Tool::pow(2,powerOfTwo);
        uint8_t check = 256/(shades);
        uint8_t valueIncrement = 256/(shades-1);
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
                image.getPixel(x_,y_) = Pixel(r,g,b);
            }
        }
    }
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
        image.setPixelMap(pixelmap);
        image.setXSize(xSize);
        image.setYSize(ySize);


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
        std::cout << "left: " << left << " right: " << right << " top: " << top << " bottom: " << bottom << "\n";
        if (bottom != -1) // Don't crop if the image is one solid colour
        {
            crop(image,right-left+1,bottom-top+1,left,top); // Crop the image
        }

    }

}

