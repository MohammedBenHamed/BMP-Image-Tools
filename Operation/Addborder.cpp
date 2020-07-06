#include "Operation.h"
namespace Operation
{
    void addBorder(Img& image, Pixel p1, Pixel p2)
    {
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        Pixel topLeft, top, topRight, right, bottomRight, bottom, bottomLeft, left;
        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                try
                {
                    topLeft = image.getPixel(x_-1,y_-1);
                }
                catch (const InvalidCoordinate& oor)
                {
                    topLeft = p2;
                }
                try
                {
                    top = image.getPixel(x_,y_-1);
                }
                catch (const InvalidCoordinate& oor)
                {
                    top = p2;
                }
                try
                {
                    topRight = image.getPixel(x_+1,y_-1);
                }
                catch (const InvalidCoordinate& oor)
                {
                    topRight = p2;
                }
                try
                {
                    right = image.getPixel(x_+1,y_);
                }
                catch (const InvalidCoordinate& oor)
                {
                    right = p2;
                }
                try
                {
                    bottomRight = image.getPixel(x_+1,y_+1);
                }
                catch (const InvalidCoordinate& oor)
                {
                    bottomRight = p2;
                }
                try
                {
                    bottom = image.getPixel(x_,y_+1);
                }
                catch (const InvalidCoordinate& oor)
                {
                    bottom = p2;
                }
                try
                {
                    bottomLeft = image.getPixel(x_-1,y_+1);
                }
                catch (const InvalidCoordinate& oor)
                {
                    bottomLeft = p2;
                }
                if (topLeft == p1 || top == p1 || topRight == p1 || right == p1 ||
                    bottomRight == p1 || bottom == p1 || bottomLeft == p1 || left == p1)
                {
                    if ( !(image.getPixel(x_,y_) == p1))
                        image.setPixel(x_,y_,p2);
                }

            }
        }
    }

    void addInnerBorder(Img& image, Pixel p1, Pixel p2, Pixel pBck)
    {
        int xSize = image.getXSize();
        int ySize = image.getYSize();

        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                if (image.getPixel(x_,y_) == pBck)
                {
                    try
                    {
                        if (image.getPixel(x_-1,y_-1) == p1) image.setPixel(x_-1,y_-1,p2);
                    }
                    catch (const InvalidCoordinate& oor){};
                    try
                    {
                        if (image.getPixel(x_,y_-1) == p1) image.setPixel(x_,y_-1,p2);
                    }
                    catch (const InvalidCoordinate& oor){};
                    try
                    {
                        if (image.getPixel(x_+1,y_-1) == p1) image.setPixel(x_+1,y_-1,p2);
                    }
                    catch (const InvalidCoordinate& oor){};
                    try
                    {
                        if (image.getPixel(x_+1,y_) == p1) image.setPixel(x_+1,y_,p2);
                    }
                    catch (const InvalidCoordinate& oor){};
                    try
                    {
                        if (image.getPixel(x_+1,y_+1) == p1) image.setPixel(x_+1,y_+1,p2);
                    }
                    catch (const InvalidCoordinate& oor){};
                    try
                    {
                        if (image.getPixel(x_,y_+1) == p1) image.setPixel(x_,y_+1,p2);
                    }
                    catch (const InvalidCoordinate& oor){};
                    try
                    {
                        if (image.getPixel(x_-1,y_+1)== p1) image.setPixel(x_-1,y_+1,p2);
                    }
                    catch (const InvalidCoordinate& oor){};
                }



            }
        }
    }
}
