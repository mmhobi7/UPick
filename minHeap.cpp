#include "minHeap.h"
#include "restaurant.h"

// credits Shane Malone Stepik 6.1.1

#include <iostream>
#include <queue>
#include <math.h>

minHeap::minHeap(int size)
{
    theHeapSize = 0;
    max = size;
    theHeap = new heapRestaurant[size];
}

minHeap::~minHeap()
{
    delete theHeap;
    theHeapSize = 0;
}

void minHeap::heapPrint()
{
    for (int i = 0; i < theHeapSize; ++i)
        std::cout << theHeap[i].item->getName() << " ";
}

int minHeap::getSize()
{
    return theHeapSize;
}

void minHeap::insert(heapRestaurant item)
{
    theHeap[theHeapSize] = item;
    theHeapSize++;
    theHeap = heapifyDown(0);
}

restaurant *minHeap::extractMax()
{
    heapRestaurant rootVal = theHeap[0];
    theHeap[0] = theHeap[--theHeapSize];
    theHeap = heapifyDown(0);
    return rootVal.item;
}

heapRestaurant *minHeap::heapifyDown(int index)
{
    int childLeft = 2 * index + 1;
    int childRight = 2 * index + 2;
    if (childLeft > theHeapSize - 1)
        return theHeap;
    int childMax = 0;
    if (theHeap[childLeft].distance > theHeap[childRight].distance)
        childMax = childLeft;
    else
        childMax = childRight;
    if (theHeap[childMax].distance > theHeap[index].distance)
    {
        heapRestaurant tempVal = theHeap[index];
        int nextIndex = childMax;
        theHeap[index] = theHeap[childMax];
        theHeap[childMax] = tempVal;
        return heapifyDown(childMax);
    }
    else
        return theHeap;
}

long long minHeap::distance(restaurant *a, restaurant *b)
{
    pair<long long, long long> a_coord;
    pair<long long, long long> b_coord;

    return sqrt(abs(pow(b_coord.first - a_coord.first, 2)) + abs(pow(b_coord.second - a_coord.second, 2)));
}

queue<restaurant *> minHeap::bfs(restaurant *src)
{
    // return top 5 restaurants from heap
    std::queue<restaurant *> relatedRestaurants;
    relatedRestaurants.push(extractMax());
    relatedRestaurants.push(extractMax());
    relatedRestaurants.push(extractMax());
    relatedRestaurants.push(extractMax());
    relatedRestaurants.push(extractMax());
    return relatedRestaurants;
}