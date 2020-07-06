#ifndef LOADCOMMAND_H
#define LOADCOMMAND_H
#define INPUT_FILE 0
#define OUTPUT_FILE 1


#include "../Baseloop.h"
#include <set>
#include <map>
#include <string>
#include <vector>
#include "../../File/File.h"
class LoadCommand : public Baseloop
{
    private:
    bool mode = INPUT_FILE; // Determines whether to store keyboard input for input or output file
    std::string fileBuffer; // Stores the input file temporarily when the output file is taken
    std::map<std::string,std::string>* fileListPtr; // Points to master fileList map
    void applyAction();
    public:
    LoadCommand(std::map<std::string,std::string>* fileListPtr);
};

#endif //LOADCOMMAND_H
