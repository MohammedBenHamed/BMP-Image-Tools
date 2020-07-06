#ifndef BASELOOP_H
#define BASELOOP_H
#include <string>
#include <iostream>
class Baseloop
{
    protected:
    std::string input; // Input taken from user
    std::string message; // Message to print out, set to "" for no message or use messagePrinted
    bool inputTaken = 1; // Determines if input should be taken from user or not
    bool isRunning = 1; // Setting to 0 Determines when the loop should stop running
    bool messagePrinted = 1; // Determines if final message is printed or not
    private:
    virtual void applyAction() = 0;
    public:
    void run();
};


#endif // BASELOOP_H
