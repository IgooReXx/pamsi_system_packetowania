//
// Created by kubab on 30.03.2024.
//

#include <string>
#include "readData.h"
#include <fstream>
#include <stdexcept>

std::string readData(std::string fileName)
{
    int length = 0;
    std::ifstream file(fileName);
    if(!file.is_open())
    {
        throw std::invalid_argument("File read failed.");
    }

    if(file)
    {
        file.seekg(0, file.end);
        length = file.tellg();
        file.seekg(0, file.beg);
    }
    length++;
    char* buffer = new char[length];

    file.read(buffer, length);
    std::string dataRead = buffer;
    delete[] buffer;
    file.close();
    return dataRead;
}