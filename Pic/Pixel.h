#ifndef PIXEL_H
#define PIXEL_H
#include <stdint.h>
#include <ostream>
struct Pixel
{
    uint8_t r, g,  b;
    Pixel(uint8_t r, uint8_t g, uint8_t b);
};

std::ostream& operator<< (std::ostream &out, const Pixel &pixel);
bool operator==(const Pixel& lhs, const Pixel& rhs);


#endif // PIXEL_H

