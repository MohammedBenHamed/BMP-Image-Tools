#include "Operation.h"
namespace Operation
{
    void addImageTo(Img& image1, Img& image2, int xBegin, int yBegin, Pixel p)
    {
        //TODO: Remove last pixel parameter to make use of alpha images instead.

        int xSize = image1.getXSize();
        int ySize = image1.getYSize();
        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                if ( (!(image1.getPixel(x_,y_) == p)) )
                {
                    try // attempt to add image1 onto image2
                    {
                        image2.setPixel(x_+xBegin,y_+yBegin,image1.getPixel(x_,y_));
                        // TODO: Make the algorithm handle alpha images correctly

                    }
                    catch (const InvalidCoordinate& oor) // ignore parts of image that won't fit
                    {}
                }
            }
        }
    }
}
