#pragma once
#include "Restaurant.h"
#include "Graph.h"
#include "maxHeap.h"
#include <map>

class App
{
    unordered_map<string, std::map<int, vector<Restaurant *>>> allRestaurants; // category, map<zipcode, vecotr<restaurants>>
    //unordered_map<string, priority_queue<Restaurant>> RelatedRestaurants; // uh idk what this is for
    // vector<string> categoryList;
    set<string> categorySet;

public:
    App();
    void setCategoryList();
    void setCategorySet();
    set<string> getCategorySet();
    string findCategory(string s);
    void addRestaurant(Restaurant *obj);
    int findZip(int zip, string cat);
    int getCategorySize(int category);
    int getZipcodeSize(int category, int zipcode);
    Restaurant *getRestaurant(int category, int zipcode, int index);
    int getListSize();
    int getListZipcodeSize(string);
    unordered_map<string, std::map<int, vector<Restaurant *>>> getList();
    Graph &getLocalGraph(string cat, int zipcode, Restaurant *source);
    // maxHeap& getLocalHeap(string cat, int zipcode, Restaurant* source);
};
