#include "Baseloop.h"

void Baseloop::run()
{
    std::cout << message; // Introductory message before input is taken
    while (isRunning)
    {
        if (inputTaken) std::getline(std::cin >> std::ws, input); // To allow inputs with spaces in them
        applyAction();
        if (messagePrinted) std::cout << message; // To give a chance for the loop to print a message before ending the loop
    }
}
