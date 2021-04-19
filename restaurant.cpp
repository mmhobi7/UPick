#include "restaurant.h"

restaurant::restaurant()
{
    name = "_name";
    rating = 0;
    address = "addy";
    category = "cat";
    coords.first = 0;
    coords.second = 0;
}
restaurant::restaurant(string _name, double _rating, string addy, string cat, int zip, double longi, double lat)
{
    name = _name;
    rating = _rating;
    address = addy;
    category = cat;
    zipcode = zip;
    coords.first = longi;
    coords.second = lat;
}

string restaurant::getName()
{
    return name;
}

double restaurant::getRating()
{
    return rating;
}

string restaurant::getAddress()
{
    return address;
}

string restaurant::getCategory()
{
    return category;
}

void restaurant::setCategory(string cat)
{
    category = cat;
}

int restaurant::getZipcode()
{
    return zipcode;
}

std::pair<double, double> restaurant::getCoords()
{
    return coords;
}

void restaurant::print()
{
    cout << "\"" << getName() << "\""
         << ". It has " << getRating() << " star(s). " << endl;
    cout << "Address: " << getAddress() << endl;
}