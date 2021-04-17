#pragma once
#include <iostream>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
using namespace std;

class Restaurant
{
    string id;
    string name;
    string address;
    int zipcode;
    string category;
    std::pair<long long, long long> coords;

public:
    double rating;
    Restaurant(string _name, double _rating, string addy, string cat, int zip, long long longi, long long lat);
    Restaurant();
    string GetName();
    double GetRating();
    string GetAddress();
    string GetCategory();
    void SetCategory(string cat);
    std::pair<long long, long long> GetCoords();
};
