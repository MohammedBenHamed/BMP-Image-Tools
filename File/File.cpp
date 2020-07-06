#include "File.h"

namespace File
{
    std::string openFile(std::string filename)
    {
        std::ifstream file(filename,std::ios::binary);
        if (!file.good()) throw InvalidFile();
        std::stringstream buffer; // Initialise buffer
        buffer << file.rdbuf(); // Buffer the file content
        std::string content = buffer.str();
        return content;
    }

    bool isValid(std::string filename)
    {
        std::ifstream file(filename);
        return file.good();
    }
    void writeFile(std::string filename, std::string content)
    {
        std::ofstream file;
        file.open(filename,std::ios::binary);
        file << content;
    }


}
