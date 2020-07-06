#include "Operation.h"
#include <set>
#include <sstream>
#include "../File/File.h"
namespace Operation
{
    void getColours(Img& image, std::string filename)
    {
        std::set<Pixel> pixelSet;
        std::stringstream colourBuffer;
        int xSize = image.getXSize();
        int ySize = image.getYSize();
        for (int y_ = 0; y_ < ySize; y_++)
        {
            for (int x_ = 0; x_ < xSize; x_++)
            {
                pixelSet.insert(image.getPixel(x_,y_));
            }
        }
        colourBuffer << "Number of colours used: " << pixelSet.size() << "\n";
        for (Pixel pixel : pixelSet)
        {
            colourBuffer << pixel << "\n";
        }

        File::writeFile(filename,colourBuffer.str());
    }

}
