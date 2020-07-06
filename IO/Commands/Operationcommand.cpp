#include "Operationcommand.h"
OperationCommand::OperationCommand(std::map<std::string,std::string>* fileListPtr, std::vector<Script>* scriptListPtr
                     , std::vector<OperationName> nameBuffer, std::vector<InputType> inputTypeList)
                     : fileListPtr(fileListPtr), scriptListPtr(scriptListPtr), nameBuffer(nameBuffer)
                     , inputTypeList(inputTypeList)
{
    std::string operationname;
    message = inputTypeList.at(0).entryMessage;
}

void OperationCommand::takeInputType()
{
    switch(inputTypeList.at(mode).name)
    {
        case INPUTFILE:
        {
            auto it = fileListPtr->find(input);
            if (it == fileListPtr->end())
            {
                message = "This file has not been loaded.\n";
                message += "Check which input files have been loaded using 'view' and enter the given output file name.\n";
            }
            else
            {
                fileBuffer = input;
                mode++;
                if (mode<inputTypeList.size()) message = inputTypeList.at(mode).entryMessage;
            }
        }
        break;
        case PIXEL:
        {
                std::istringstream iss(input);
                std::vector<int> values;
                for (int i; iss>>i;)
                {
                    values.push_back(i); // Turn input into a vector of int values
                }
                // STEP 1: Check if user has made an invalid input (not entering 3 numbers)
                if (values.size() != 3)
                {
                    message = "Incorrect pixel format. Each number must be 0-255. For example: '255 0 0' for a red pixel.";
                }
                else
                {
                    bool validInput = 1;
                    for (int value : values)
                    {
                        // STEP 2: Check if the user has made an invalid input (one of the 3 numbers is not in the 0-255 range)
                        if (value>255 || value<0)
                        {
                            validInput =0;
                        }
                    }
                    if (validInput)
                    {
                        pListBuffer.push_back(Pixel(uint8_t(values.at(0)),uint8_t(values.at(1)),uint8_t(values.at(2)) ) );
                        mode++;
                        if (mode<inputTypeList.size()) message = inputTypeList.at(mode).entryMessage;
                    }
                    else message = "Incorrect pixel format. Each number must be 0-255. For example: '255 0 0' for a red pixel.";
                }

            }
        break;
        case MULPIXEL:
            {
            // STEP 1: Check if user has input a / to end entering pixels without entering any pixels
            if (input == "/" && pListBuffer.empty())
            {
                message = "You have not entered any pixels yet! Please enter at least one\n";
            }
            // STEP 2: Check if user has input a / with at least one pixel entered
            else if (input == "/" && !(pListBuffer.empty() ) )
            {
                mode++;
                if (mode<inputTypeList.size()) message = inputTypeList.at(mode).entryMessage;
            }
            else
            {
                std::istringstream iss(input);
                std::vector<int> values;
                for (int i; iss>>i;)
                {
                    values.push_back(i); // Turn input into a vector of int values
                }
                // STEP 3: Check if user has made an invalid input (not entering 3 numbers)
                if (values.size() != 3)
                {
                    message = "Incorrect pixel format. Each number must be 0-255. For example: '255 0 0' for a red pixel.\n";
                }
                else
                {
                    bool validInput = 1;
                    for (int value : values)
                    {
                        // STEP 4: Check if the user has made an invalid input (one of the 3 numbers is not in the 0-255 range)
                        if (value>255 || value<0)
                        {
                            validInput =0;
                        }
                    }
                    if (validInput)
                    {
                        pListBuffer.push_back(Pixel(uint8_t(values.at(0)),uint8_t(values.at(1)),uint8_t(values.at(2)) ) );
                        message = "Pixel successfully added. Feel free to add more or type '/' to continue.\n";
                    }
                    else message = "Incorrect pixel format. Each number must be 0-255. For example: '255 0 0' for a red pixel.\n";
                }

            }
        }

        break;
        case OPTION:
        {
            bool found = 0;
            for (int i = 0; i<(int)inputTypeList.at(mode).optionList.size(); i++)
            {
                if (input == inputTypeList.at(mode).optionList.at(i))
                {
                    found = 1;
                    nameChoice = i;
                    mode++;
                    if (mode<inputTypeList.size()) message = inputTypeList.at(mode).entryMessage;

                }
            }
            if (!found)
            {
                message = "Invalid answer. Please enter one of the following:";
                for (std::string input : inputTypeList.at(mode).optionList)
                {
                    message+= " '" + input + "'";
                }
                message += "\n";
            }
        }
        break;
        case NUMBER:
        {
            bool error = 0;
            std::istringstream iss(input);
            std::vector<int> values;
            for (int i; iss>>i;)
            {
                values.push_back(i); // Turn input into a vector of int values
            }
            if (values.size() != 1) error = 1;
            if (nameBuffer.at(0) == LIMITCOLOUR)
            {
                if (values.at(0) < 0 || values.at(0) > 7) error = 1;
            }
            if (error)
            {
                message = "Incorrect number format, please try again.\n";
                if (nameBuffer.at(0) == LIMITCOLOUR) message+= "Integer must be between 1 and 7.\n";
            }
            else
            {
                nListBuffer.push_back(values.at(0));
                mode++;
                if (mode<inputTypeList.size()) message = inputTypeList.at(mode).entryMessage;
            }


        }
        break;
        case COORDINATE:
        {
            bool error = 0;
            std::istringstream iss(input);
            std::vector<unsigned int> values;
            for (unsigned int i; iss>>i;)
            {
                values.push_back(i); // Turn input into a vector of int values
            }
            if (values.size() != 2) error = 1;
            else
            {
                if ( (nameBuffer.at(0) == CROP && mode == 1)  || nameBuffer.at(0) == ADDIMAGETO )
                {
                    if (values.at(0) < 0  || values.at(0) >= ImageFile::getInfo::xSize(fileBuffer)) error = 1;
                    if (values.at(1) < 0  || values.at(1) >= ImageFile::getInfo::ySize(fileBuffer)) error = 1;
                }
                else if (nameBuffer.at(0) == CROP && mode == 2)
                {
                    if (values.at(0) <= 0  ||
                        values.at(0) > ImageFile::getInfo::xSize(fileBuffer) - nListBuffer.at(0) ) error = 1;
                    if (values.at(1) <= 0  ||
                        values.at(1) > ImageFile::getInfo::ySize(fileBuffer) - nListBuffer.at(1) ) error = 1;
                }
            }
            if (error)
            {
                message = "Incorrect coordinate format, please try again.\n";
                if ( (nameBuffer.at(0) == CROP && mode == 1)  || nameBuffer.at(0) == ADDIMAGETO )
                    message+= "Coordinates must be within image range. x: 0 to "
                    + std::to_string(ImageFile::getInfo::xSize(fileBuffer)-1) + " y: 0 to "
                    + std::to_string(ImageFile::getInfo::ySize(fileBuffer)-1) + "\n";
                else if (nameBuffer.at(0) == CROP && mode == 2)
                    message+= "Coordinates must be within image range. x: 1 to "
                    + std::to_string(ImageFile::getInfo::xSize(fileBuffer) - nListBuffer.at(0)) + " y: 1 to "
                    + std::to_string(ImageFile::getInfo::ySize(fileBuffer) - nListBuffer.at(1)) + "\n";
            }
            else
            {
                nListBuffer.push_back(values.at(0));
                nListBuffer.push_back(values.at(1));
                mode++;
                if (mode<inputTypeList.size()) message = inputTypeList.at(mode).entryMessage;
            }

        }
        break;
        case OTHERFILE:
        {
            if (File::isValid(input))
            {
                sListBuffer.push_back(input);
                mode++;
                if (mode<inputTypeList.size()) message = inputTypeList.at(mode).entryMessage;
            }
            else
            {
                message = "Invalid file. Please make sure this file exist in the directory.\n";
            }
        }
        break;
        default:
        // Throw exception
        break;

    }
}



void OperationCommand::applyAction()
{
    if (input == "?")
    {
        message = "";
        isRunning = 0;
    }
    else
    {
        takeInputType();
    }
    if (mode==inputTypeList.size())
    {
        scriptListPtr->push_back(Script(nameBuffer.at(nameChoice),fileBuffer,pListBuffer,nListBuffer,sListBuffer));
        message = "Script successfully added.\n";
        isRunning = 0;
    }
};
