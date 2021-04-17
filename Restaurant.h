#pragma once
#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;

class Restaurant
{
    string name;
    string address;
    string category;
    int zipCode;
    std::pair<long long, long long> coords;

public:
    Restaurant();
    Restaurant(string _name, double _rating, string addy, string cat, int zip, long long longi, long long lat);
    double rating;
    string getName();
    double getRating();
    string getAddress();
    string getCategory();
    int getZipcode();
    void print();
    void setCategory(string cat);
    std::pair<long long, long long> getCoords();
};
