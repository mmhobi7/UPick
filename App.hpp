#pragma once
#include "Restaurant.hpp"

class App
{
    unordered_map<string, vector<Restaurant *>> allRestaurants; // make this the unordered_set<std::pair<string,Restaurant>>
    //unordered_map<category name, vector of restaurants>
    //set of strings of category
    unordered_map<string, priority_queue<Restaurant>> RelatedRestaurants;
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
