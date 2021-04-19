#pragma once
#include "Restaurant.h"

using namespace std;

class heapRestaurant
{
public:
    heapRestaurant(Restaurant *, long long);
    heapRestaurant();
    Restaurant *item;
    long long distance;
};
