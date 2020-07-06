#ifndef PIXEL_H
#define PIXEL_H
#include <stdint.h>
#include <ostream>
#include <algorithm>
#include <cmath>
struct Pixel
{
    uint8_t r, g, b, a;
    Pixel();
    Pixel(uint8_t r, uint8_t g, uint8_t b);
    Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    Pixel(float h, float s, float l);
    Pixel(float h, float s, float l, uint8_t a);
};

std::ostream& operator<< (std::ostream &out, const Pixel &pixel);
bool operator==(const Pixel& lhs, const Pixel& rhs);
bool operator<(const Pixel& lhs, const Pixel& rhs);

#endif // PIXEL_H



