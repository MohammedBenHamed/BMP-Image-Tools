#ifndef INVALIDBYTE_H
#define INVALIDBYTE_H
#include <exception>
class InvalidByte: public std::exception
{
  virtual const char* what() const throw()
  {
    return "Value entered is invalid";
  }
};
#endif // INVALIDBYTE_H


