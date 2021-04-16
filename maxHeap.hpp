#pragma once
// credits Muhamed Hobi Stepik 6.1.1

class maxHeap
{
public:
    maxHeap(int);
    ~maxHeap();
    void heapRemove();
    int readHeap();
    void heapPrint();
    int getSize();
    int extractMax();

private:
    void balance();
    int *theHeap;
    int theHeapSize;
};
