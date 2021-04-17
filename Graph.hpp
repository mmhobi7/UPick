#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>
#include "Restaurant.h"
using namespace std;


class Graph
{
private:
    unordered_map<int, vector<pair<int, int>>> graph;
    set<int> v;
    unordered_map<Restaurant*, int> mapper;
    int index;

public:
    void insertEdge(Restaurant* from, Restaurant* to, int weight);
    bool isEdge(Restaurant* from, Restaurant* to);
    int getWeight(Restaurant* from, Restaurant* to);
    vector<Restaurant*> getAdjacent(Restaurant* vertex);

    // bfs
    

    // dfs


};
