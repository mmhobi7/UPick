#pragma once
#include "restaurant.h"
#include "graph.h"
#include "maxHeap.h"
#include <map>

class app
{
    unordered_map<string, std::map<int, vector<restaurant *>>> allRestaurants; // category, map<zipcode, vecotr<restaurants>>
    //unordered_map<string, priority_queue<Restaurant>> RelatedRestaurants; // uh idk what this is for
    // vector<string> categoryList;
    set<string> categorySet;

public:
    app();
    void setCategoryList();
    void setCategorySet();
    set<string> getCategorySet();
    string findCategory(string s);
    void addRestaurant(restaurant *obj);
    int findZip(int zip, string cat);
    int getCategorySize(int category);
    int getZipcodeSize(int category, int zipcode);
    restaurant *getRestaurant(int category, int zipcode, int index);
    int getListSize();
    int getListZipcodeSize(string);
    unordered_map<string, std::map<int, vector<restaurant *>>> getList();
    graph getLocalGraph(string cat, int zipcode, restaurant *source);
    maxHeap getLocalHeap(string cat, int zipcode, restaurant *source);
    // maxHeap& getLocalHeap(string cat, int zipcode, Restaurant* source);
};
