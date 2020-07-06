#ifndef EXECUTECOMMAND_H
#define EXECUTECOMMAND_H
#include <map>
#include <vector>
#include <string>
#include "../Baseloop.h"
#include "../Script.h"
#include "../../Pic/Img.h"
#include "../../File/ImageFile.h"
#include "../Operationname.h"
#include "../../Operation/Operation.h"
class ExecuteCommand : public Baseloop
{
    private:
    std::map<std::string,Img> imageList; // Key = Output file name, mapped value = Image data
    std::map<std::string,std::string>* fileListPtr; // Points to master fileList map
    std::vector<Script>* scriptListPtr; // Points to master scriptList vector
    void execute(Script& script);
    void applyAction();
    public:
    ExecuteCommand(std::map<std::string,std::string>* fileListPtr, std::vector<Script>* scriptListPtr);
};

#endif //EXECUTECOMMAND_H
