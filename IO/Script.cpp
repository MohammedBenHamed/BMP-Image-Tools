#include "Script.h"

Script::Script(OperationName name,std::string filePerformedOn,
                std::vector<Pixel> pList,std::vector<int> nList,std::vector<std::string> sList)
                : name(name), filePerformedOn(filePerformedOn), pList(pList), nList(nList), sList(sList)
                {
                    //Handle invalid inputs e.g. a colourise operation with no Pixels entered.
                };


std::ostream& operator<< (std::ostream &out, const Script &script)
{
   switch (script.name)
   {
        case MONOCHROME:
        {
            out << "Monochrome ";
            out << script.filePerformedOn;
        }
        break;
        case CHANGECOLOUR:
        {
            out << "Change colour of ";
            out << script.filePerformedOn;
            if (script.pList.size()>2) // If there are more than 1 pixel to compare, then only mention the amount of pixels
            {
                out << " if (" << script.pList.size()-1 << " Pixels)";
            }
            else out << script.pList.at(0);
            out << " to ";
            out << script.pList.back();

        }
        break;
        case CHANGECOLOURIFNOT:
        {
            out << "Change colour of ";
            out << script.filePerformedOn;
            if (script.pList.size()>2) // If there are more than 1 pixel to compare, then only mention the amount of pixels
            {
                out << " if not (" << script.pList.size()-1 << " Pixels)";
            }
            else out << script.pList.at(0);
            out << " to ";
            out << script.pList.back();
        }
        break;
        case LIMITCOLOUR:
        {
            out << "Limit colour of ";
            out << script.filePerformedOn;
            out << " to 2^";
            out << script.nList.at(0);
            out << " colours per grey element (";
            out << std::pow(std::pow(2,script.nList.at(0)),3);
            out << " colours in total)";
        }
        break;
        case CROP:
        {
            out << "Crop ";
            out << script.filePerformedOn;
            out << " from: (";
            out << script.nList.at(2) << "," << script.nList.at(3) << ")";
            out << " size of: (" << script.nList.at(0) << "," << script.nList.at(1) << ")";

        }
        break;
        case CROPEDGES:
        {
            out << "Crop edges of ";
            out << script.filePerformedOn;
            out << " with " << script.pList.at(0) << " as background";
        }
        break;
        case ADDIMAGETO:
        {
            out << "Add image onto ";
            out << script.filePerformedOn;
            out << " from ";
            out << script.sList.at(0);
            out << " starting from (";
            out << script.nList.at(0) << "," << script.nList.at(1) << ")";
            out << " with " << script.pList.at(0) << " as background";

        }
        break;
        case ADDBORDER:
        {
            out << "Add border onto ";
            out << script.filePerformedOn;
            out << " replacing colour " << script.pList.at(0) << " with " << script.pList.at(1);

        }
        break;
        case ADDINNERBORDER:
        {
            out << "Add inner border to ";
            out << script.filePerformedOn;
            out << " replacing colour " << script.pList.at(0) << " with " << script.pList.at(1);
            out << " using " << script.pList.at(2) << " as background";
        }
        break;
        case COLOURISE:
        {
            out << "Colourise ";
            out << script.filePerformedOn;
            out << " using " << script.pList.at(0);
        }
        break;
        default:
        // TODO: Handle this by throwing an exception
        break;
   }

    return out;
}
