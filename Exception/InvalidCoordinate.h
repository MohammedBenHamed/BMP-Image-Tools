#ifndef INVALIDCOORDINATE_H
#define INVALIDCOORDINATE_H
#include <exception>
class InvalidCoordinate: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Coordinate entered is invalid";
  }
};
#endif // INVALIDCOORDINATE_H



