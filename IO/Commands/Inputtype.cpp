#include "Inputtype.h"
InputType::InputType(InputName name, std::string entryMessage, std::vector<std::string> optionList)
 : name(name), entryMessage(entryMessage), optionList(optionList) {};

InputType::InputType(InputName name, std::string entryMessage)
 : name(name), entryMessage(entryMessage) {};

