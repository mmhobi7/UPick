#pragma once
#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class restaurant
{
    string name;
    string address;
    string category;
    int zipcode;
    std::pair<double, double> coords;

public:
    restaurant();
    restaurant(string _name, double _rating, string addy, string cat, int zip, double longi, double lat);
    double rating;
    string getName();
    double getRating();
    string getAddress();
    string getCategory();
    int getZipcode();
    void print();
    void setCategory(string cat);
    std::pair<double, double> getCoords();
};
