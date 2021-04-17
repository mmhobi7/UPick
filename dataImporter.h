#pragma once
#include <string>
#include <fstream>
#include "App.h"
#include "Graph.h"
// credits Muhamed Hobi Stepik 6.1.1

class dataImporter
{
public:
    dataImporter(std::string);
    ~dataImporter();
    void read(App& myApp, Graph& myGraph);

private:
    std::string fileName;
    std::ifstream fileStream;
};
