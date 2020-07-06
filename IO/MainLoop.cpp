#include "MainLoop.h"

consoleIO::consoleIO()
{
    message = "Please enter a command.\n";

};


std::unique_ptr<Baseloop> consoleIO::getCommand(std::string input)
{
    std::unique_ptr<Baseloop> bp(nullptr);
    if (input == "load") bp = std::unique_ptr<Baseloop>{ new LoadCommand(&fileList) };
    else if (input == "monochrome")
    {

        std::vector<InputType> inputTypeList
        {
            InputType
            (
                INPUTFILE,
                "Enter the output file name of the image you would like to make monochrome. Type '?' to stop at any time.\n"
            )
        };
        std::vector<OperationName> nameBuffer
        {
            MONOCHROME
        };
        bp = std::unique_ptr<Baseloop> {new OperationCommand(&fileList,&scriptList,nameBuffer,inputTypeList)};
    }
    else if (input == "changecolour")
    {
        std::vector<InputType> inputTypeList
        {
            InputType
            (
                OPTION,
                "Will the pixel of the original image be changed if it equals the target pixels or not?\n Enter 'if' or 'if not'\n",
                std::vector<std::string> { "if", "if not"}
            ),
            InputType
            (
                INPUTFILE,
                "Enter the output file name of the image you would like to change the colour of. Type '?' to stop at any time.\n"
            ),
            InputType
            (
                MULPIXEL,
                "Start entering at least one target Pixel. Enter '/' when you are done typing.\n"
            ),
            InputType
            (
                PIXEL,
                "Which colour would you like to change the pixels to?\n"
            )
        };
        std::vector<OperationName> nameBuffer
        {
            CHANGECOLOUR, CHANGECOLOURIFNOT
        };
        bp = std::unique_ptr<Baseloop> {new OperationCommand(&fileList,&scriptList,nameBuffer,inputTypeList)};

    }
    else if (input == "limitcolour")
    {

        std::vector<InputType> inputTypeList
        {
            InputType
            (
                INPUTFILE,
                "Enter the output file name of the image you would like to limit the colour of  . Type '?' to stop at any time.\n"
            ),
            InputType
            {
                NUMBER,
                "How many bits per gray level should the image be limited to?\n"
            }
        };
        std::vector<OperationName> nameBuffer
        {
            LIMITCOLOUR
        };
        bp = std::unique_ptr<Baseloop> {new OperationCommand(&fileList,&scriptList,nameBuffer,inputTypeList)};

    }
    else if (input == "crop")
    {

        std::vector<InputType> inputTypeList
        {
            InputType
            (
                INPUTFILE,
                "Enter the output file name of the image you would like to crop. Type '?' to stop at any time.\n"
            ),
            InputType
            {
                COORDINATE,
                "From which starting coordinate should the image be cropped?\n"
            },
            InputType
            {
                COORDINATE,
                "How big will the cropped image be?\n"
            }
        };
        std::vector<OperationName> nameBuffer
        {
            CROP
        };
        bp = std::unique_ptr<Baseloop> {new OperationCommand(&fileList,&scriptList,nameBuffer,inputTypeList)};

    }
    else if (input == "cropedges")
    {

        std::vector<InputType> inputTypeList
        {
            InputType
            (
                INPUTFILE,
                "Enter the output file name of the image you would like to crop the edges of. Type '?' to stop at any time.\n"
            ),
            InputType
            {
                PIXEL,
                "Which pixel colour will serve as the background?\n"
            },
        };
        std::vector<OperationName> nameBuffer
        {
            CROPEDGES
        };
        bp = std::unique_ptr<Baseloop> {new OperationCommand(&fileList,&scriptList,nameBuffer,inputTypeList)};

    }

    else if (input == "addimageto")
    {

        std::vector<InputType> inputTypeList
        {
            InputType
            (
                INPUTFILE,
                "Enter the output file name of the image you would like to add another image onto. Type '?' to stop at any time.\n"
            ),
            InputType
            {
                OTHERFILE,
                "What is the name of the image file you would like to add onto the selected output?\n"
            },
            InputType
            {
                COORDINATE,
                "From which starting coordinate should the image be added?\n"
            },
            InputType
            {
                PIXEL,
                "Which colour should serve as the background?\n"
            },

        };
        std::vector<OperationName> nameBuffer
        {
            ADDIMAGETO
        };
        bp = std::unique_ptr<Baseloop> {new OperationCommand(&fileList,&scriptList,nameBuffer,inputTypeList)};

    }
    else if (input == "addborder")
    {

        std::vector<InputType> inputTypeList
        {
            InputType
            (
                INPUTFILE,
                "Enter the output file name of the image you would like to add a border to. Type '?' to stop at any time.\n"
            ),
            InputType
            {
                PIXEL,
                "Which colour should the border target?\n"
            },
            InputType
            {
                PIXEL,
                "Which colour will the border have?\n"
            },

        };
        std::vector<OperationName> nameBuffer
        {
            ADDBORDER
        };
        bp = std::unique_ptr<Baseloop> {new OperationCommand(&fileList,&scriptList,nameBuffer,inputTypeList)};

    }
    else if (input == "addinnerborder")
    {

        std::vector<InputType> inputTypeList
        {
            InputType
            (
                INPUTFILE,
                "Enter the output file name of the image you would like to add an inner border to. Type '?' to stop at any time.\n"
            ),
            InputType
            {
                PIXEL,
                "Which colour should the border target?\n"
            },
            InputType
            {
                PIXEL,
                "Which colour will the border have?\n"
            },
            InputType
            {
                PIXEL,
                "Which colour is the background?\n"
            },

        };
        std::vector<OperationName> nameBuffer
        {
            ADDINNERBORDER
        };
        bp = std::unique_ptr<Baseloop> {new OperationCommand(&fileList,&scriptList,nameBuffer,inputTypeList)};

    }
    else if (input == "colourise")
    {

        std::vector<InputType> inputTypeList
        {
            InputType
            (
                INPUTFILE,
                "Enter the output file name of the image you would like to colourise. Type '?' to stop at any time.\n"
            ),
            InputType
            {
                PIXEL,
                "What coloured tint should the image have?\n"
            },

        };
        std::vector<OperationName> nameBuffer
        {
            COLOURISE
        };
        bp = std::unique_ptr<Baseloop> {new OperationCommand(&fileList,&scriptList,nameBuffer,inputTypeList)};

    }
    else if (input == "getcolours")
    {
        bp = std::unique_ptr<Baseloop> {new GetColoursCommand(&fileList)};

    }
    else if (input == "execute")  bp = std::unique_ptr<Baseloop>{ new ExecuteCommand(&fileList,&scriptList) };
    else if (input == "view")
    {
        std::stringstream viewInfo;
        viewInfo << "File List:\n";
        if (fileList.empty()) viewInfo << "(empty)\n";
        else
        {
            for (auto it = fileList.begin(); it != fileList.end(); ++it)
            {
                viewInfo << "Image output: " << it->first << " from file: " << it->second << "\n";
            }
        }
        viewInfo << "Script List:\n";
        if (scriptList.empty()) viewInfo << "(empty)\n";
        else
        {
            for (Script script: scriptList)
            {
                viewInfo << script << "\n";
            }
        }
        bp = std::unique_ptr<Baseloop>{ new MsgCommand(viewInfo.str()) };
    }
    else if (input == "help")
    {
        std::stringstream help;
        help << "List of commands: \n";
        help << "load:\t\t Loads a file to be performed on.\n";
        help << "view:\t\t Views files that have been entered and operations that are ready to be executed.\n";
        help << "monochrome:\t\t Generates a black and white version of the input file.\n";
        help << "changecolour:\t\t Changes the colour value of any pixel that meets a set requirement.\n";
        help << "limitcolour:\t\t Limits the amount of colours used in a picture. Set by power of 2, e.g. 64 colours.\n";
        help << "crop:\t\t Crops the picture by the user's choice.\n";
        help << "cropedges:\t\t Automatically crops any edges by setting background colour.\n";
        help << "addimageto:\t\t Adds one image onto another by setting a background colour\n";
        help << "addborder:\t\t Adds an inner or outer border to an image\n";
        help << "colourise:\t\t Gives a tint to an image by specifying a colour.\n";
        help << "getcolors:\t\t Writes a list of colours used in one image to a file.\n";
        help << "execute:\t\t Performs the operations.\n";
        help << "exit:\t\t quits program.\n";
        bp = std::unique_ptr<Baseloop>{ new MsgCommand(help.str()) };
    }

    else if (input == "exit")
    {
        bp = std::unique_ptr<Baseloop>{ new MsgCommand("Program successfully exited.\n")};
        isRunning = 0;
        messagePrinted = 0;
    }
    return bp;
}

void consoleIO::applyAction()
{
    std::unique_ptr<Baseloop> bp =  getCommand(input);
    if (bp != nullptr)
    {
        bp->run();
        message = "Please enter a command.\n";
    }
    else message = "This command does not exist. Enter 'help' for list of commands.\n";

}

