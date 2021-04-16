#pragma once
#include <string>
#include <fstream>
#include "tools/json.hpp"
// credits Muhamed Hobi Stepik 6.1.1

using json = nlohmann::json;

class dataImporter
{
public:
    dataImporter(std::string);
    ~dataImporter();
    void read();

private:
    std::string fileName;
    std::ifstream fileStream;
    json j;
};