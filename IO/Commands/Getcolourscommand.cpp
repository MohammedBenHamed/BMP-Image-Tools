
#include "Getcolourscommand.h"
GetColoursCommand::GetColoursCommand(std::map<std::string,std::string>* fileListPtr): fileListPtr(fileListPtr)
{
    message = "Start by entering the input file you want to obtain the colours from. Type '?' to exit at any time.\n";
}
void GetColoursCommand::applyAction()
{
    if (input == "?")
    {
        message = "";
        isRunning = 0;
    }
    else
    {
        if (mode == INPUT_FILE)
        {
            if (File::isValid(input))
            {
                message = "Now please enter the name of the file that this text file will output to.\n";
                fileBuffer = input;
                mode = OUTPUT_FILE;
            }
            else
            {
                message = "Invalid file. Please make sure this file exist in the directory.\n";
            }
        }
        else if (mode == OUTPUT_FILE)
        {
            Img img = ImageFile::Read(fileBuffer);
            Operation::getColours(img,input);
            message = "Colours have been successfully counted and added to " + input + ".\n";
            isRunning = 0;
        }
    }
};

