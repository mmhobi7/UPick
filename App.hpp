#pragma once
#include "Restaurant.hpp"

class App
{
    unordered_map<string, vector<Restaurant*>> allRestaurants; //map<category,map<zip code,vector<restaurant>
    //unordered_map<category name, vector of restaurants>
    //set of strings of category
    unordered_map<string, priority_queue<Restaurant>> NearbyRestaurants; // 
    //unordered_map<string, graph<Restaurant>> NearbyRestaurants; //
    vector<string> categoryList;
    set<string> categorySet;
public:
    App();
    void SetCategoryList();
    void SetCategorySet();
    vector<string> GetCategoryList();
    string FindCategory(string s);
    void AddRestaurant(Restaurant* obj);
};
