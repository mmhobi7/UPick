#pragma once
#include "Restaurant.h"

class App {
    unordered_map<string, vector<Restaurant*>> allRestaurants; // make this the unordered_set<std::pair<string,Restaurant>>
    //unordered_map<category name, vector of restaurants>
    //set of strings of category
    vector<string> categoryList;
    unordered_map<string, priority_queue<Restaurant>> RelatedRestaurants;
public:
    App();
    void SetCategoryList();
    vector<string> GetCategoryList();
    void AddRestaurant(Restaurant obj);
};