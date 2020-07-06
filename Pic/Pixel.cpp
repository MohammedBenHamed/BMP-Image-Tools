#include "Pixel.h"

// | ----- Constructors ----- |

Pixel::Pixel() : r(uint8_t(255)), g(uint8_t(255)), b(uint8_t(255)), a(uint8_t(255)) {}; // default to white pixel

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b)
{
    a = 0xFF; // default value
};
Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {};

Pixel::Pixel(float h, float s, float l, uint8_t a) : a(a) // convert HSL to RGB
{
    float c, x, m, rDash, gDash, bDash;
    c = ( 1- std::abs(2*l-1)   )*s;
    x = c * (1 - std::abs(std::fmod((h/60),2) - 1));
    m = l - c/2;
    if (h>= 0 && h<60) {rDash = c; gDash = x; bDash = 0;}
    else if (h>= 60 && h<120) {rDash = x; gDash = c; bDash = 0;}
    else if (h>= 120 && h<180) {rDash = 0; gDash = c; bDash = x;}
    else if (h>= 180 && h<240) {rDash = 0; gDash = x; bDash = c;}
    else if (h>= 240 && h<300) {rDash = x; gDash = 0; bDash = c;}
    else if (h>= 300 && h<360) {rDash = c; gDash = 0; bDash = x;}
    r = (uint8_t)std::round((rDash+m)*255);
    g = (uint8_t)std::round((gDash+m)*255);
    b = (uint8_t)std::round((bDash+m)*255);

}

Pixel::Pixel(float h, float s, float l) : Pixel(h,s,l,0xFF) {};


// | ----- Overloading operators ----- |


std::ostream& operator<< (std::ostream &out, const Pixel &pixel)
{
     out << "{" << (int)pixel.r << "," << (int)pixel.g << "," << (int)pixel.b << "}"; // actual output done here
    if (pixel.a != 0xFF) out << " transparency: " << (int)pixel.a;
    return out; // return std::ostream so calls can be chained to operator <<
}

bool operator==(const Pixel& lhs, const Pixel& rhs)
{
    return (lhs.r == rhs.r && lhs.g == rhs.g && lhs.b == rhs.b &&  lhs.a == rhs.a);
}

bool operator<(const Pixel& lhs, const Pixel& rhs)
{
    if (lhs.r != rhs.r) return (lhs.r<rhs.r);
    else if (lhs.g != rhs.g) return (lhs.g<rhs.g);
    else if (lhs.b != rhs.b) return (lhs.b<rhs.b);
    else if (lhs.a != rhs.a) return (lhs.a < rhs.a);
    else return 0;

}

