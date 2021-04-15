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