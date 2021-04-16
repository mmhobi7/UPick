#pragma once
#include <string>
#include <fstream>
// credits Muhamed Hobi Stepik 6.1.1

class dataImporter
{
public:
    dataImporter(std::string);
    ~dataImporter();
    void read();

private:
    std::string fileName;
    std::ifstream fileStream;
};