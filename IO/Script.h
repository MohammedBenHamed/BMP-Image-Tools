#ifndef SCRIPT_H
#define SCRIPT_H
#include "Operationname.h"
#include "../Pic/Pixel.h"
#include <string>
#include <vector>
#include <ostream>
#include <cmath>
struct Script
{
    OperationName name;

    std::string filePerformedOn; // All operations will alter an input image.
    //This value is ALL/ which means the operation will be performed on all input files

    // Following parameters which the operation use will vary from operation to operation
    std::vector<Pixel> pList; // Pixels
    std::vector<int> nList; // Numbers may be used e.g. Coordinate or size
    std::vector<std::string> sList; // Strings may be used e.g. the name of another input

    Script(OperationName name,std::string filePerformedOn,
           std::vector<Pixel> pList,std::vector<int> nList,std::vector<std::string> sList);
    // If any of the parameters are not used, enter an empty
};

std::ostream& operator<< (std::ostream &out, const Script &script);



#endif // SCRIPT_H

