#ifndef MAINLOOP_H
#define MAINLOOP_H
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include "Baseloop.h"
#include "Commands/Loadcommand.h"
#include "Commands/Msgcommand.h"
#include "Commands/Executecommand.h"
#include "Commands/Operationcommand.h"
#include "Commands/Getcolourscommand.h"
#include "Commands/Inputtype.h"
#include "Script.h"
class consoleIO : public Baseloop
{
    private:
    std::map<std::string,std::string> fileList;
    std::vector<Script> scriptList;
    std::unique_ptr<Baseloop> getCommand(std::string input); // Launches command from main menu
    void applyAction();
    public:
    consoleIO();
};

#endif // MAINLOOP_H
