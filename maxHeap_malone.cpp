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
}int* heapifyDown(int arr[], int size, int index)
{
    int childLeft = 2*index + 1;
    int childRight = 2*index + 2;
    if (childLeft > size - 1)
        return arr;
    int childMax = 0;
    if (arr[childLeft] > arr[childRight])
        childMax = childLeft;
    else
        childMax = childRight;
    if (arr[childMax] > arr[index]) {
        int tempVal = arr[index];
        int nextIndex = childMax;
        arr[index] = arr[childMax];
        arr[childMax] = tempVal;
        return heapifyDown(arr,size,childMax);
    }
    else
        return arr;
    
}
int* extractMax(int arr[], int size)
{
    arr[0] = arr[--size];
    return heapifyDown(arr, size, 0);
    
}


//Don't change main
int main() {

   int size;
   cin >> size;
   int* arr = new int[size];

    for(int i = 0; i < size; i++)
        cin >> arr[i];

   arr =  extractMax(arr, size);
   for(int i = 0; i < size - 1; i++)
      cout << arr[i] << " ";

   return 0;
}
int* heapifyDown(int arr[], int size, int index)
{
    int childLeft = 2 * index + 1;
    int childRight = 2 * index + 2;
    if (childLeft > size - 1)
        return arr;
    int childMax = 0;
    if (arr[childLeft] > arr[childRight])
        childMax = childLeft;
    else
        childMax = childRight;
    if (arr[childMax] > arr[index]) {
        int tempVal = arr[index];
        int nextIndex = childMax;
        arr[index] = arr[childMax];
        arr[childMax] = tempVal;
        return heapifyDown(arr, size, childMax);
    }
    else
        return arr;

}
int* extractMax(int arr[], int size)
{
    arr[0] = arr[--size];
    return heapifyDown(arr, size, 0);

}


//Don't change main
int main() {

    int size;
    cin >> size;
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
        cin >> arr[i];

    arr = extractMax(arr, size);
    for (int i = 0; i < size - 1; i++)
        cout << arr[i] << " ";

    return 0;
}