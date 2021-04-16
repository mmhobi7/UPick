#include "dataImporter.hpp"

#include <fstream>
#include <sstream> // std::stringstream

dataImporter::dataImporter(std::string file)
{
    fileName = file;
    fileStream.open(fileName);
}
dataImporter::~dataImporter()
{
    fileStream.close();
}
void dataImporter::read()
{
}