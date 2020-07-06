#include "Msgcommand.h"
MsgCommand::MsgCommand(std::string message)
{
    this->message = message;
    inputTaken = 0;
    isRunning = 0;
}

void MsgCommand::applyAction() {}; // Do nothing
