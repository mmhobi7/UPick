#include "Restaurant.h"

Restaurant::Restaurant()
{
    name = "_name";
    rating = 0;
    address = "addy";
    category = "cat";
    coords.first = 0;
    coords.second = 0;
}
Restaurant::Restaurant(string _name, double _rating, string addy, string cat, int zip, long long longi, long long lat)
{
    name = _name;
    rating = _rating;
    address = addy;
    category = cat;
    zipCode = zip;
    coords.first = longi;
    coords.second = lat;
}

string Restaurant::getName()
{
    return name;
}

double Restaurant::getRating()
{
    return rating;
}

string Restaurant::getAddress()
{
    return address;
}

string Restaurant::getCategory()
{
    return category;
}

void Restaurant::setCategory(string cat)
{
    category = cat;
}

int Restaurant::getZipcode()
{
    return zipCode;
}

std::pair<long long, long long> Restaurant::getCoords()
{
    return coords;
}

void Restaurant::print(){
    cout << "Name: " << getName() << " Rating: " << getRating() << " Category: " << getCategory() << " ZipCode: " << getZipcode() << endl;
}