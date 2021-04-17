#pragma once
#include "Restaurant.hpp"

class App
{
    unordered_map<string, vector<Restaurant *>> allRestaurants; // make this the unordered_set<std::pair<string,Restaurant>>
    //unordered_map<category name, vector of restaurants>
    //set of strings of category
    unordered_map<string, priority_queue<Restaurant>> RelatedRestaurants;

public:
    App();
    vector<string> categoryList;
    void SetCategoryList();
    vector<string> GetCategoryList();
    void AddRestaurant(Restaurant* obj);
};
