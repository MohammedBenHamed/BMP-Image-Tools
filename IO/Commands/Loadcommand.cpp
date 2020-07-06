#include "Loadcommand.h"
LoadCommand::LoadCommand(std::map<std::string,std::string>* fileListPtr): fileListPtr(fileListPtr)
{
    message = "Start by entering the input file you want to use. Type '?' to stop at any time.\n";
}
void LoadCommand::applyAction()
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
                message = "Now please enter the name of the file that this image will output to.\n";
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
            //TODO: Handle situation when user enters a duplicate key by notifying them if they wish to overwrite previous pair
            fileListPtr->insert(std::pair<std::string,std::string>(input,fileBuffer));
            fileBuffer.clear();
            message = "File successfully added. Enter ? to go back, otherwise feel free to add more files.\n";
            mode = INPUT_FILE;
        }
    }
};

