#ifndef OPERATIONCOMMAND_H
#define OPERATIONCOMMAND_H
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include "../Script.h"
#include "../Baseloop.h"
#include "../../Pic/Pixel.h"
#include "Inputtype.h"
#include "../../File/ImageFile.h"
class OperationCommand : public Baseloop
{
    private:
    std::map<std::string,std::string>* fileListPtr; // Points to master fileList map
    std::vector<Script>* scriptListPtr; // Points to master scriptList vector

    void applyAction();
    std::vector<Pixel> pListBuffer; // Buffer to enter Pixels before creating Script object
    std::vector<int> nListBuffer;
    std::vector<std::string> sListBuffer;
    std::vector<OperationName> nameBuffer; // Possibility to store more than one OperationName to be judged using OPTION
    std::string fileBuffer; // Buffer to enter file operated on.
    std::vector<InputType> inputTypeList;
    uint8_t mode = 0;
    uint8_t nameChoice = 0; // Determines which name from list to choose. Default is 0.
    void takeInputType();
    void prepareNextMessage();

    public:
    OperationCommand(std::map<std::string,std::string>* fileListPtr, std::vector<Script>* scriptListPtr
                     , std::vector<OperationName> nameBuffer, std::vector<InputType> inputTypeList);
};
#endif //OPERATIONCOMMAND_H
