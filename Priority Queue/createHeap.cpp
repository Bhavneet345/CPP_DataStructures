#include<iostream>
using namespace std;

void insertHeap(int *minHeap, int size, int element)
{
    if(size == 0)
    {
        minHeap[0] = element;
        return;
    }
    int child = size;
    minHeap[child] = element;
    int parent = (child - 1) / 2;
    while(parent >= 0)
    {
        if(minHeap[parent] > minHeap[child])
        {
            int temp = minHeap[parent];
            minHeap[parent] = minHeap[child];
            minHeap[child] = temp;
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break;
        }
    }
    return;
}

void constructMinHeap(int *arr, int size)
{
    int element;
    for(int i = 0; i < size; i++)
    {
        cin >> element;
        insertHeap(arr, i, element);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int *minHeap = new int[n];
    constructMinHeap(minHeap, n);
    for(int i = 0; i < n; i++)
    {
        cout << minHeap[i] << " ";
    }
    return 0;
}
