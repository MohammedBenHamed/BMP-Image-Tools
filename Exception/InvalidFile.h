#ifndef INVALIDCOORDINATE_H
#define INVALIDCOORDINATE_H
#include <exception>
class InvalidFile: public std::exception
{
  virtual const char* what() const throw()
  {
    return "File name entered is invalid";
  }
};
#endif // INVALIDCOORDINATE_H



