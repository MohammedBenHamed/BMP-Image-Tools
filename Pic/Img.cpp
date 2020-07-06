#include "Img.h"
Img::Img(unsigned int xSize, unsigned int ySize, Pixel p)
{
    // remember to handle bad_alloc exceptions
    if (xSize == 0 || ySize == 0) throw InvalidCoordinate();
    this->xSize = xSize;
    this->ySize = ySize;
    PixelMap pixelmap;
    for (unsigned int y_ = 0; y_ < ySize; y_++)
    {
        for (unsigned int x_ = 0; x_ < xSize; x_++)
        {
            pixelmap.push_back(p);
        }
    }
    this->pixelmap = pixelmap;
}

Img::Img(unsigned int xSize, unsigned int ySize, PixelMap pixelmap)
{
    if (xSize == 0 || ySize == 0) throw InvalidCoordinate();
    if (pixelmap.size() != xSize*ySize)
    {
        throw IncompletePixelMap(); // There must be an adequate amount of pixels in the PixelMap
    }
    this->xSize = xSize;
    this->ySize = ySize;
    this->pixelmap = pixelmap;
}

Pixel Img::getPixel(unsigned int x, unsigned int y) const
{
    if (x>=xSize || y>=ySize || x<0 || y<0)
    {
        throw InvalidCoordinate();
    }
    return pixelmap.at(x+y*xSize);
}

void Img::setPixel(unsigned int x, unsigned y, Pixel pixel)
{
    if (x>=xSize || y>=ySize || x<0 || y<0)
    {
        throw InvalidCoordinate();
    }
    pixelmap.at(x+y*xSize) = pixel;
}





unsigned int Img::getXSize() const
{
    return xSize;
}
unsigned int Img::getYSize() const
{
    return ySize;
}




std::ostream& operator<< (std::ostream &out,  const Img &img)
{
    out << "xSize: " << img.getXSize() << " ySize: " << img.getYSize();
    out << "\n[\n";
    for (unsigned int y_ = 0; y_<img.getYSize(); y_++)
    {
        for(unsigned int x_ = 0; x_<img.getXSize(); x_++)
        {
            out << img.getPixel(x_,y_);
            if (!(x_==img.getXSize()-1 && y_==img.getYSize()-1)) // print commas until last coordinate
            out << ", ";
        }
        out << "\n";
    }
     out << "]";
    return out; // return std::ostream so we can chain calls to operator <<
}

