#include "dataImporter.h"
#include <sstream> // std::stringstream

using std::string;

dataImporter::dataImporter(std::string file)
{
    fileName = file;
    fileStream.open(fileName);
    if (!fileStream.is_open())
    {
        cout << "File " << fileName << " not found. " << endl;
        exit(1);
    }
}
dataImporter::~dataImporter()
{
    fileStream.close();
}

bool dataImporter::isValidZipcode(string zipcode)
{
    for (auto i = zipcode.begin(); i != zipcode.end(); i++)
    {
        if (!isdigit(*i))
        {
            return false;
        }
    }
    if (zipcode.length() <= 0)
    {
        return false;
    }
    return true;
}

void dataImporter::read(app &myApp)
{
    // figure out what categories to reading in
    string name, address, category, sRating, id, temp, sLongitude, sLatitude;
    double rating;
    double longitude, latitude;
    string zipcode;
    string line;
    bool is_restaurant = false;

    getline(fileStream, temp); // parse through column names (dont need)
    while (!fileStream.eof())
    {
        // count++;
        getline(fileStream, temp, ','); // row number (dont need)
        getline(fileStream, id, ',');
        getline(fileStream, name, ',');
        getline(fileStream, address, ',');
        getline(fileStream, temp, ','); // city (dont need)
        address += ", " + temp;
        getline(fileStream, temp, ','); // state (dont need)
        address += ", " + temp;
        getline(fileStream, temp, ','); // postal code (dont need)
        address += ", " + temp;
        zipcode = temp;
        getline(fileStream, sLatitude, ',');
        getline(fileStream, sLongitude, ',');
        getline(fileStream, sRating, ','); // num stars
        getline(fileStream, temp, ',');    // num reviews (dont need)
        getline(fileStream, temp, ',');    // is open (dont need)
        getline(fileStream, line);         // list of categories
        latitude = stod(sLatitude);
        longitude = stod(sLongitude);
        rating = stod(sRating);
        // parse thru name to see if it is a restaurant
        istringstream iss1(name);
        string s;

        // parse thru categories string to see if any categories are familiar
        // if it category was not found in the name
        if (!is_restaurant)
        {
            istringstream iss2(line);
            s = "";
            while (!iss2.eof())
            {
                iss2 >> s;
                // category = myApp.findCategory(s);
                // if (category != "")
                // {
                    is_restaurant = true;
                    if (isValidZipcode(zipcode))
                    {
                        myApp.addRestaurant(new restaurant(name, rating, address, s, stoi(zipcode), longitude, latitude));
                    }
                    break;
                // }
            }
        }
        is_restaurant = false;
    }
}