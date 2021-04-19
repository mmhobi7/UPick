#pragma once
#include "restaurant.h"
#include "graph.h"
#include "minHeap.h"
#include <map>

class app
{
    unordered_map<string, std::map<int, vector<restaurant *>>> allRestaurants; // category, map<zipcode, vecotr<restaurants>>
    set<string> categorySet;

public:
    app();
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
    minHeap getLocalHeap(string cat, int zipcode, restaurant *source);
};
