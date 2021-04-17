#include "Restaurant.h"


Restaurant::Restaurant() {
    name = "_name";
    rating = 0;
    address = "addy";
    category = "cat";
    coords.first = 0;
    coords.second = 0;
}
Restaurant::Restaurant(string _name, double _rating, string addy, string cat, long long longi, long long lat) {
    name = _name;
    rating = _rating;
    address = addy;
    category = cat;
    coords.first = longi;
    coords.second = lat;
}

string Restaurant::GetName() {
    return name;
}

double Restaurant::GetRating() {
    return rating;
}

string Restaurant::GetAddress() {
    return address;
}

string Restaurant::GetCategory() {
    return category;
}

void Restaurant::SetCategory(string cat) {
    category = cat;
}

std::pair<long long, long long> Restaurant::GetCoords() {
    return coords;
}
