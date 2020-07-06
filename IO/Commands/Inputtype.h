#ifndef INPUTTYPE_H
#define INPUTTYPE_H
#include <string>
#include <vector>
#include "Inputname.h"
struct InputType
{
    InputName name;
    std::string entryMessage;
    std::vector<std::string> optionList; // List of options that user may have to choose between different OperationNames

    InputType(InputName name, std::string entryMessage,  std::vector<std::string> optionList);
    InputType(InputName name, std::string entryMessage);
};
#endif //INPUTTYPE_H
