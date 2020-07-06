#ifndef MSGCOMMAND_H
#define MSGCOMMAND_H
#include "../Baseloop.h"
#include <string>
class MsgCommand : public Baseloop
{
    private:
    void applyAction();
    public:
    MsgCommand(std::string message);
};

#endif //MSGCOMMAND_H

