#include "dataImporter.h"

#include <sstream> // std::stringstream
using std::string;

dataImporter::dataImporter(std::string file)
{
    fileName = file;
    fileStream.open(fileName);
}
dataImporter::~dataImporter()
{
    fileStream.close();
}
void dataImporter::read(App &myApp, Graph &myGraph)
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
    while (!fileStream.eof()) {
        count++;
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
        if (!is_restaurant) {
            istringstream iss2(line);
            s = "";
            while (!iss2.eof())
            {
                iss2 >> s;
                category = myApp.findCategory(s);
                if (category != "")
                {
                    is_restaurant = true;
                    if (zipCode.length() == 5) {
                        myApp.addRestaurant(new Restaurant(name, rating, address, category, stoi(zipCode), longitude, latitude));
                    }
                    break;
                }
            }
        }
        /*if(!is_restaurant)
           category = "other";*/
        is_restaurant = false;
    }

}