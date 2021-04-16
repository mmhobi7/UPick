#include "maxHeap.hpp"

// credits Muhamed Hobi Stepik 6.1.1

#include <iostream>
#include <queue>

maxHeap::maxHeap(int size)
{
    theHeapSize = size;
    theHeap = new int[size];
}

maxHeap::~maxHeap()
{
    delete theHeap;
}

int maxHeap::readHeap()
{
    int currElement = 0;
    int i = 0;
    std::cin >> currElement;
    while (currElement != -1) {
        theheap[i++] = currElement;
        std::cin >> currElement;
    }
    return i;
}


void heapRemove(int* theheap, int& size) {
    theheap[0] = theheap[--size];
    int i = 0;
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;
    int minChild = 0;
    if (theheap[leftChild] > theheap[rightChild])
        minChild = rightChild;
    else
        minChild = leftChild;
    while (theheap[i] > theheap[minChild]) {
        int tempVal = theheap[i];
        theheap[i] = theheap[minChild];
        theheap[minChild] = tempVal;
        i = minChild;
        leftChild = 2*i + 1;
        if (leftChild > size - 1)
            break;
        rightChild = 2*i + 2;
        if (theheap[leftChild] > theheap[rightChild])
            minChild = rightChild;
        else
            minChild = leftChild;
    }
    return;
}

void heapPrint(int* theheap, int size) {
    for (int i = 0; i < size; ++i)
        std::cout << theheap[i] << " ";
}

int maxHeap::getSize()
{
    return theHeapSize;
}

int maxHeap::extractMax(int arr[], int size)
{
    int rootVal = arr[0];
    heapRemove();
    return rootVal;
}
