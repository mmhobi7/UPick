#include "maxHeap.h"

// credits Muhamed Hobi Stepik 6.1.1

#include <iostream>
#include <queue>

/* maxHeap::maxHeap(int size)
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
    std::queue<int> yeet;
    int val = 0;
    while (val != -1)
    {
        std::cin >> val;
        if (val != -1)
        {
            yeet.push(val);
        }
        else
        {
            break;
        }
    }
    int i = 0;
    while (!yeet.empty())
    {
        theHeap[i] = yeet.front();
        yeet.pop();
        i++;
    }
    return i;
}

void maxHeap::balance()
{
    for (int i = 0; i < theHeapSize; i++)
    {
        if (theHeap[i] == NULL)
        {
            if (i * 2 + 1 < theHeapSize || i * 2 + 2 < theHeapSize)
            {
                if (i * 2 + 1 < theHeapSize)
                {
                    if (i * 2 + 2 < theHeapSize)
                    {
                        if (theHeap[i * 2 + 1] < theHeap[i * 2 + 2])
                        {
                            theHeap[i] = theHeap[i * 2 + 1];
                            theHeap[i * 2 + 1] = NULL;
                            balance();
                            return;
                        }
                        else
                        {
                            theHeap[i] = theHeap[i * 2 + 2];
                            theHeap[i * 2 + 2] = NULL;
                            balance();
                            return;
                        }
                    }
                    else
                    {
                        theHeap[i] = theHeap[i * 2 + 1];
                        theHeap[i * 2 + 1] = NULL;
                        balance();
                        return;
                    }
                }
                else
                {
                    theHeap[i] = theHeap[i * 2 + 2];
                    theHeap[i * 2 + 2] = NULL;
                    balance();
                    return;
                }
            }
            else
            {
                if (i + 1 < theHeapSize)
                {
                    if (i + 2 < theHeapSize)
                    {
                        if (theHeap[i + 1] <= theHeap[i + 2])
                        {
                            theHeap[i] = theHeap[i + 1];
                            theHeap[i + 1] = NULL;
                            balance();
                            return;
                        }
                        else
                        {
                            theHeap[i] = theHeap[i + 2];
                            theHeap[i + 2] = NULL;
                            balance();
                            return;
                        }
                    }
                    else
                    {
                        theHeap[i] = theHeap[i + 1];
                        theHeap[i + 1] = NULL;
                        balance();
                        return;
                    }
                }
            }
        }
    }
}

void maxHeap::heapRemove()
{
    theHeap[0] = NULL;
    balance();
    theHeapSize -= 1;
}

void maxHeap::heapPrint()
{
    for (int i = 0; i < theHeapSize; i++)
    {
        std::cout << theHeap[i] << " ";
    }
    //use cout to print the array representing the heap
}

int maxHeap::getSize()
{
    return theHeapSize;
}

// is this a good idea???
int maxHeap::front() {
    return theHeap[0];
} */

//////// MAX HEAP MALONE
#include <iostream>
#include <sstream>

int readHeap(int* theheap) {
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

maxHeap::maxHeap(Restaurant *r) {


}
