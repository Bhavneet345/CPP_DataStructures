#include<iostream>
using namespace std;

void insertHeap(int *minHeap, int parent, int child)
{
    if(parent < 0)
    {
        return;
    }   
    if(minHeap[parent] > minHeap[child])
    {
        int temp = minHeap[parent];
        minHeap[parent] = minHeap[child];
        minHeap[child] = temp;
        insertHeap(minHeap, (parent - 1) / 2, parent);
    }
    return;
}

void constructMinHeap(int *minheap, int size)
{
    int element, parent;
    for(int i = 0; i < size; i++)
    {
        cin >> element;
        minheap[i] = element;
        insertHeap(minheap, (i - 1) / 2, i);
    }
    return;
}

void removeMinhelper(int *minHeap, int size, int parent)
{
    if(parent >= size - 1)
    {
        return;
    }
    int leftchild = (2 * parent) + 1, rightchild = (2 * parent) + 2, childIndex, minchild;
    if(leftchild >= size && rightchild >= size)
    {
        return;
    }
    if(leftchild < size && rightchild < size)
    {
        minchild = min(minHeap[leftchild], minHeap[rightchild]);
    }
    else if(leftchild < size)
    {
        minchild = minHeap[leftchild];
    }
    else 
    {
        minchild = minHeap[rightchild];   
    }
    if(minHeap[parent] > minchild)
    {
        if(minchild == minHeap[leftchild])
        {
            childIndex = leftchild;
        }
        else
        {
            childIndex =rightchild;
        }
        int temp = minHeap[parent];
        minHeap[parent] = minHeap[childIndex];
        minHeap[childIndex] = temp;
        removeMinhelper(minHeap, size, childIndex);
    }
    else
    {
        return;
    }
}

void removemin(int *minheap, int &n)
{
    if(n == 0)
    {
        return;
    }
    minheap[0] = minheap[n - 1];
    n = n - 1;
    removeMinhelper(minheap, n, 0);
    return;
}

void printHeap(int *minHeap, int size)
{
    if(size == 0)
    {
        return;
    }
    for(int i = 0; i < size; i++)
    {
        cout << minHeap[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    int *minHeap = new int[n];
    constructMinHeap(minHeap, n);
    printHeap(minHeap, n);
    removemin(minHeap, n);
    printHeap(minHeap, n);
    removemin(minHeap, n);
    printHeap(minHeap, n);
    return 0;
}