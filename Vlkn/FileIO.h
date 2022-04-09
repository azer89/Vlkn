#ifndef __FILE_IO_H__
#define __FILE_IO_H__

#include <vector>
#include <fstream>

namespace VlknFileIO
{
    static std::vector<char> readFile(const std::string& filename)
    {
        /*
        ate: Start reading at the end of the file
        binary: Read the file as binary file 
        */
        std::ifstream file(filename, std::ios::ate | std::ios::binary);
        if (!file.is_open())
        {
            throw std::runtime_error("Failed to open file " + filename);
        }

        size_t fileSize = (size_t)file.tellg();
        std::vector<char> buffer(fileSize);
        file.seekg(0);
        file.read(buffer.data(), fileSize);
        file.close();
        return buffer;
    }

}

#endif