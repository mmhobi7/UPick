#pragma once
#include <string>
#include <fstream>
#include "app.h"
#include "graph.h"
// credits Muhamed Hobi Stepik 6.1.1

class dataImporter
{
public:
    dataImporter(std::string);
    ~dataImporter();
    void read(app &myApp);
    bool isValidZipcode(string);

private:
    std::string fileName;
    std::ifstream fileStream;
};
