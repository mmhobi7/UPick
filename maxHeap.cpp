#include "maxHeap.hpp"

// credits Muhamed Hobi Stepik 6.1.1

#include <iostream>
#include <queue>

maxHeap::maxHeap(int size)
{
    theHeapSize = size;
    theHeap = new Restaurant[size];
}

maxHeap::~maxHeap()
{
    delete theHeap;
}

int maxHeap::readHeap()
{
    // Restaurant currElement = 0;
    // int i = 0;
    // std::cin >> currElement;
    // while (currElement != -1)
    // {
    //     theHeap[i++] = currElement;
    //     std::cin >> currElement;
    // }
    // return i;
}

void maxHeap::heapRemove()
{
    theHeap[0] = theHeap[--theHeapSize];
    int i = 0;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int minChild = 0;
    if (theHeap[leftChild].rating > theHeap[rightChild].rating)
        minChild = rightChild;
    else
        minChild = leftChild;
    while (theHeap[i].rating > theHeap[minChild].rating)
    {
        Restaurant tempVal = theHeap[i];
        theHeap[i] = theHeap[minChild];
        theHeap[minChild] = tempVal;
        i = minChild;
        leftChild = 2 * i + 1;
        if (leftChild > theHeapSize - 1)
            break;
        rightChild = 2 * i + 2;
        if (theHeap[leftChild].rating > theHeap[rightChild].rating)
            minChild = rightChild;
        else
            minChild = leftChild;
    }
    return;
}

void maxHeap::heapPrint()
{
    for (int i = 0; i < theHeapSize; ++i)
        std::cout << theHeap[i].GetName() << " ";
}

int maxHeap::getSize()
{
    return theHeapSize;
}

Restaurant maxHeap::extractMax()
{
    Restaurant rootVal = theHeap[0];
    heapRemove();
    return rootVal;
}
