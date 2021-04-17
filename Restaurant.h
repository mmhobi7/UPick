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
    int zipcode;
    std::pair<long long, long long> coords;

public:
    Restaurant();
    Restaurant(string _name, double _rating, string addy, string cat, int zip, long long longi, long long lat);
    double rating;
    string GetName();
    double GetRating();
    string GetAddress();
    string GetCategory();
    void SetCategory(string cat);
    std::pair<long long, long long> GetCoords();
};
