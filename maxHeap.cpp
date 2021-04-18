#include "maxHeap.h"
#include "Restaurant.h"

// credits Muhamed Hobi Stepik 6.1.1

#include <iostream>
#include <queue>

maxHeap::maxHeap(int size)
{
    theHeapSize = size;
    theHeap = new heapRestaurant[size];
}

maxHeap::~maxHeap()
{
    delete theHeap;
    theHeapSize = 0;
}

void maxHeap::heapPrint()
{
    for (int i = 0; i < theHeapSize; ++i)
        std::cout << theHeap[i].item->getName() << " ";
}

int maxHeap::getSize()
{
    return theHeapSize;
}

Restaurant *maxHeap::extractMax()
{
    heapRestaurant rootVal = theHeap[0];
    theHeap[0] = theHeap[--theHeapSize];
    theHeap = heapifyDown(0);
    return rootVal.item;
}

heapRestaurant *maxHeap::heapifyDown(int index)
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