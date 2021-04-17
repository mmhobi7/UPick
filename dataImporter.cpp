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
void dataImporter::read(App& myApp)
{
    // figure out what categories to reading in
    string name, address, category,s_rating, id, temp, s_longitude, s_latitude;
    double rating;
    long long longitude, latitude;
    string line;
    bool is_restaurant = false;


    getline(fileStream, temp); // parse through column names (dont need)
    while(!fileStream.eof()) {
        getline(fileStream, temp, ','); // row number (dont need)
        getline(fileStream, id, ',');
        getline(fileStream, name, ',');
        getline(fileStream, address, ',');
        getline(fileStream, temp, ','); // city (dont need)
        getline(fileStream, temp, ','); // state (dont need)
        getline(fileStream, temp, ','); // postal code (dont need)
        getline(fileStream, s_latitude, ',');
        getline(fileStream, s_longitude, ',');
        getline(fileStream, s_rating, ','); // num stars
        getline(fileStream, temp, ','); // num reviews (dont need)
        getline(fileStream, temp, ','); // is open (dont need)
        getline(fileStream, line); // list of categories

        latitude = stoll(s_latitude);
        longitude = stoll(s_longitude);
        rating = stod(s_rating);
        // parse thru name to see if it is a restaurant
        istringstream iss1(name);
        string s;
        set<string> catList;
        vector<string> v_catList = myApp.GetCategoryList();
        for(int i = 0; i < v_catList.size(); i++) {
            catList.insert(v_catList[i]);
        }

        while(!iss1.eof()) {
            iss1 >> s;
            if(catList.find(s) != catList.end()) {
                is_restaurant = true;
                category = s;
                break;
            }
        }

        // parse thru categories string to see if any categories are familiar
        // if it category was not found in the name
        if(!is_restaurant) {
            istringstream iss2(line);
            s = "";
            while (!iss2.eof()) {
                iss2 >> s;
                if (catList.find(s) != catList.end()) {
                    is_restaurant = true;
                    category = s;
                    break;
                }
            }
        }

        // create a restaurant if appropriate
        if(is_restaurant) {
            Restaurant* a = new Restaurant(name, rating, address, category, longitude, latitude);
            myApp.AddRestaurant(a);
            is_restaurant = false;
        }
    }
}
