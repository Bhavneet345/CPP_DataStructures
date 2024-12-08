#include<iostream>
using namespace std;

void constructMaxHeap(int *arr, int child)
{
    if(child <= 0)
    {
        return;
    }
    int parent = (child - 1) / 2;
    if(arr[parent] < arr[child])
    {
        int temp = arr[parent];
        arr[parent] = arr[child];
        arr[child] = temp;
        constructMaxHeap(arr, parent);
    }
    return;
}

void removeMax(int *arr, int size)
{
    if(size <= 1)
    {
        return;
    }
    int parent = 0, maxindex = 0;
    int left = (2 * parent) + 1, right = (2 * parent) + 2;
    while(left < size)
    {
        maxindex = parent;
        if(arr[maxindex] < arr[left])
        {
            maxindex = left;
        }
        if(right < size && arr[maxindex] < arr[right])
        {
            maxindex = right;
        }
        if(maxindex == parent)
        {
            return;
        }
        int temp = arr[parent];
        arr[parent] = arr[maxindex];
        arr[maxindex] = temp;
        parent = maxindex;
        left = (2 * parent) + 1, right = (2 * parent) + 2;
    }
    return;
}

void heapSortMaxheap(int *arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        constructMaxHeap(arr, i);
    }
    int temp = arr[0];
    arr[0] = arr[size - 1];
    arr[size - 1] = temp;
    --size;
    for(int i = size; i > 1; i--)
    {
        removeMax(arr, i);
        int temp = arr[0];
        arr[0] = arr[i - 1];
        arr[i - 1] = temp;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    heapSortMaxheap(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}