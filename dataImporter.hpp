#pragma once
#include <string>
#include <fstream>
#include "App.hpp"
// credits Muhamed Hobi Stepik 6.1.1

class dataImporter
{
public:
    dataImporter(std::string);
    ~dataImporter();
    void read(App& myApp);

private:
    std::string fileName;
    std::ifstream fileStream;
    std::string tmp;
};
