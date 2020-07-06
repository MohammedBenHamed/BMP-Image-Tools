#include "Executecommand.h"
ExecuteCommand::ExecuteCommand(std::map<std::string,std::string>* fileListPtr, std::vector<Script>* scriptListPtr)
: fileListPtr(fileListPtr), scriptListPtr(scriptListPtr)
{
    inputTaken = 0;
};
void ExecuteCommand::execute(Script& script)
{
    auto it = imageList.find(script.filePerformedOn);
            // TODO: Handle exception where the file is not found
    switch (script.name)
   {
        case MONOCHROME:
        {
            Operation::monochrome(it->second);
        }
        break;
        case CHANGECOLOUR:
        {
            Pixel p = script.pList.back();
            std::vector<Pixel> pList(script.pList.begin(),script.pList.end()-1);
            Operation::changeColour(it->second,pList,p);
        }
        break;
        case CHANGECOLOURIFNOT:
        {
            Pixel p = script.pList.back();
            std::vector<Pixel> pList(script.pList.begin(),script.pList.end()-1);
            Operation::changeColourIfNot(it->second,pList,p);
        }
        break;
        case LIMITCOLOUR:
        {
            Operation::limitColour(it->second,script.nList.at(0));
        }
        break;
        case CROP:
        {
            Operation::crop(it->second,script.nList.at(2),script.nList.at(3),script.nList.at(0),script.nList.at(1));
        }
        break;
        case CROPEDGES:
        {
            Operation::cropEdges(it->second,script.pList.at(0));
        }
        break;
        case ADDIMAGETO:
        {
            Img image = ImageFile::Read(script.sList.at(0));
            Operation::addImageTo(image,it->second,script.nList.at(0),script.nList.at(1),
                                  script.pList.at(0));
        }
        break;
        case ADDBORDER:
        {
            Operation::addBorder(it->second,script.pList.at(0),script.pList.at(1));
        }
        break;
        case ADDINNERBORDER:
        {
            Operation::addInnerBorder(it->second,script.pList.at(0),script.pList.at(1),script.pList.at(2));
        }
        break;
        case COLOURISE:
        {
            Operation::colourise(it->second,script.pList.at(0));
        }
        break;
        default:
        // TODO: Handle this by throwing an exception
        break;
   }
}



void ExecuteCommand::applyAction()
{
    // Add all the images to a vector to be operated on.
    for (auto it = fileListPtr->begin(); it != fileListPtr->end(); ++it)
    {
        //TODO: Handle invalid file names
        imageList.insert(std::pair<std::string,Img>(it->first,ImageFile::Read(it->second)));
    }

    for (auto it = scriptListPtr->begin(); it != scriptListPtr->end(); ++it)
    {
        execute(*it);
    };
    for (auto it = imageList.begin(); it != imageList.end(); ++it)
    {
        ImageFile::WriteAs::BMP24(it->second,it->first);
    }
    imageList.clear();

    message = "Commands successfully executed!\n";
    isRunning = 0;
};
