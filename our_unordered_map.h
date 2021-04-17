#pragma once

#include "Restaurant.h"
class our_unordered_map
{
private:
    int lsize;
    int capacity;
    Restaurant *values;
    float loadsize = 0.80;
    std::hash<string> my_hash;

public:
    our_unordered_map();

    void insert(Restaurant);

    bool has(Restaurant);

    void rem(Restaurant);

    int size();
};
