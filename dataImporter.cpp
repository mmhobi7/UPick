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
    string name, address, category, s_rating, id, temp, s_longitude, s_latitude;
    double rating;
    long long longitude, latitude;
    string zipCode;
    string line;
    bool is_restaurant = false;
    int count = 0;
    int numRestaurants = 0;

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
        zipCode = temp;
        getline(fileStream, s_latitude, ',');
        getline(fileStream, s_longitude, ',');
        getline(fileStream, s_rating, ','); // num stars
        getline(fileStream, temp, ',');     // num reviews (dont need)
        getline(fileStream, temp, ',');     // is open (dont need)
        getline(fileStream, line);          // list of categories
        latitude = stoll(s_latitude);
        longitude = stoll(s_longitude);
        rating = stod(s_rating);
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
                category = myApp.findCategory(s);
                if (category != "")
                {
                    is_restaurant = true;
                    if (isValidZipcode(zipCode))
                    {
                        cout << name << " " << count++ << " zipcode: " << zipCode << endl;
                        myApp.addRestaurant(new restaurant(name, rating, address, category, stoi(zipCode), longitude, latitude));
                        numRestaurants++;
                    }
                    else
                    {
                        cout << name << " " << count++ << " zipcosde: " << zipCode << endl;
                    }
                    break;
                }
            }
        }
        /*if(!is_restaurant)
           category = "other";*/
        is_restaurant = false;
    }
    cout << "num: " << numRestaurants << endl;
}