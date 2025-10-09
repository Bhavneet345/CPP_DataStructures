#include<iostream>
#include<vector>
using namespace std;

void helper(int *minheap, int child)
{
    if(child <= 0)
    {
        return;
    }
    int parent = (child - 1) / 2;
    while(child > 0)
    {
        parent = (child - 1) / 2;   
        if(minheap[parent] > minheap[child])
        {
            int temp = minheap[parent];
            minheap[parent] = minheap[child];
            minheap[child] = temp;
        }
        else
        {
            break;
        }
        child = parent;
    }
    return;
}

void constructHeap(int *minheap, int size)
{
    for(int i = 1; i < size; i++)
    {
        helper(minheap, i);
    }
    return;
}

void heapSort(int *minheap, int size)
{
    constructHeap(minheap, size);
    while(size > 1)
    {
        int temp = minheap[size - 1];
        minheap[size - 1] = minheap[0];
        minheap[0] = temp;

        size--;

        int minindex = 0, parent = 0;
        int leftchild = (2 * parent) + 1, rightchild = (2 * parent) + 2;

        while(leftchild < size)
        {
            minindex = parent;
            if(minheap[minindex] > minheap[leftchild])
            {
                minindex = leftchild;
            }
            if(rightchild < size && minheap[rightchild] < minheap[minindex])
            {
                minindex = rightchild;
            }
            if(minindex == parent)
            {
                break;
            }

            int temp = minheap[parent];
            minheap[parent] = minheap[minindex];
            minheap[minindex] = temp;

            parent = minindex;
            leftchild = (2 * parent) + 1, rightchild = (2 * parent) + 2;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *minheap = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> minheap[i];
    }
    heapSort(minheap, n);
    for(int i = 0; i < n; i++)
    {
        cout << minheap[i] << " ";
    }
    return 0;
}