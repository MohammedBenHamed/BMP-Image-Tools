#ifndef INCOMPLETEPIXELMAP_H
#define INCOMPLETEPIXELMAP_H
#include <exception>
class IncompletePixelMap: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Pixel map has not been completed";
  }
};
#endif // INCOMPLETEPIXELMAP_H




