#include "Operation.h"
namespace Operation
{

    namespace
    {
        namespace
        {
            double rDash, gDash, bDash, cmax, cmin, diff, h, s, l;
        }
        void calculateVariables(Pixel p)
        {
            rDash = (double)p.r/255;
            gDash = (double)p.g/255;
            bDash = (double)p.b/255;
            cmax = std::max(rDash,gDash);
            cmax = std::max(cmax,bDash);
            cmin = std::min(rDash,gDash);
            cmin = std::min(cmin,bDash);
            diff = cmax - cmin;
            l = (cmax+cmin)/2;
        }
        double getHue(Pixel p)
        {
            calculateVariables(p);
            if (diff == 0) h = 0;
            else if (cmax == rDash) h = 60*std::fmod((gDash-bDash)/diff,6);
            else if (cmax == gDash) h = 60*(  ((bDash-rDash)/diff) +2);
            else if (cmax == bDash) h = 60*(  ((rDash-gDash)/diff) +4);
            h = std::round(h);
            if (h<0) h = 360+h;
            return h;
        }
        double getSat(Pixel p)
        {
            calculateVariables(p);
            if (diff == 0) s = 0;
            else s = (diff)/(1-std::abs(2*l-1));
            return s;
        }
    }

    void colourise(Img& image, Pixel p) // Change to incorporate different colours
    {
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                Pixel pixel = image.getPixel(x_,y_);
                short grey = (pixel.r + pixel.g + pixel.b)/3;
                float greyProportion = (float)grey/255; // ranges from 0 to 1;
                image.setPixel(x_,y_,Pixel(float(getHue(p)),float(getSat(p)),greyProportion));
            }
        }
    }
}
