#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include "restaurant.h"
using namespace std;

class graph
{
private:
    unordered_map<int, vector<pair<int, int>>> theGraph;
    set<int> v;
    unordered_map<restaurant *, int> mapper;
    unordered_map<int, restaurant *> reverseMapper;
    int index;

public:
    graph();
    void insertEdge(restaurant *from, restaurant *to, int weight);
    bool isEdge(restaurant *from, restaurant *to);
    int getWeight(restaurant *from, restaurant *to);
    vector<restaurant *> getAdjacent(restaurant *vertex);
    long long distance(restaurant *a, restaurant *b);
    int getSize();

    // bfs
    queue<restaurant *> bfs(restaurant *src);
};
