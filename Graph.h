#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include "Restaurant.h"
using namespace std;

class Graph
{
private:
    unordered_map<int, vector<pair<int, int>>> graph;
    set<int> v;
    unordered_map<Restaurant *, int> mapper;
    unordered_map<int, Restaurant *> reverseMapper;
    int index;

public:
    void insertEdge(Restaurant *from, Restaurant *to, int weight);
    bool isEdge(Restaurant *from, Restaurant *to);
    int getWeight(Restaurant *from, Restaurant *to);
    vector<Restaurant *> getAdjacent(Restaurant *vertex);
    long long distance(Restaurant* a, Restaurant* b);

    // bfs
    queue<Restaurant*> bfs(Restaurant* src);


};
