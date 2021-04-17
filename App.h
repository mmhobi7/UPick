#pragma once
#include "Restaurant.h"
#include <map>

class App
{
    unordered_map<string, std::map<int, vector<Restaurant *>>> allRestaurants; // category, map<zipcode, vecotr<restaurants>>
    //unordered_map<string, priority_queue<Restaurant>> RelatedRestaurants; // uh idk what this is for
    vector<string> categoryList;
    set<string> categorySet;

public:
    App();
    void setCategoryList();
    void setCategorySet();
    vector<string> getCategoryList();
    string findCategory(string s);
    void addRestaurant(Restaurant *obj);
};
