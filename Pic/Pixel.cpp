#include "Pixel.h"
Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b)
{

};
std::ostream& operator<< (std::ostream &out, const Pixel &pixel)
{
     out << "{" << (int)pixel.r << "," << (int)pixel.g << "," << (int)pixel.b << "}"; // actual output done here

    return out; // return std::ostream so we can chain calls to operator<<
}


bool operator==(const Pixel& lhs, const Pixel& rhs)
{
    return (lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b);
}
