#include<iostream>
#include<vector>
using namespace std;

class minpriorityQueue
{
    vector<int> pq;
    public:
    minpriorityQueue()
    {}
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int retSize()
    {
        return pq.size();
    }
    int getMin()
    {
        if(isEmpty())
        {
            return -1;
        }
        return pq[0];
    }
    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        int parentIndex = (childIndex - 1) / 2;
        while(childIndex > 0)
        {
            parentIndex = (childIndex - 1) / 2;
            if(pq[parentIndex] > pq[childIndex])
            {
                int temp = pq[parentIndex];
                pq[parentIndex] = pq[childIndex];
                pq[childIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    int deleteMin()
    {
        if(isEmpty())
        {
            return;
        }
        int minelement = pq[0]; 
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parent = 0;
        int leftchild = (2 * parent) + 1, rightchild = (2 * parent) + 2;
        int minIndex = parent;
        while(leftchild < pq.size())
        {
            minIndex = parent;
            if(pq[minIndex] > pq[leftchild])
            {
                minIndex = leftchild;
            }
            if(rightchild < pq.size() && pq[minIndex] > pq[rightchild])
            {
                minIndex = rightchild;
            }
            if(minIndex == parent)
            {
                break;
            }
            int temp = pq[parent];
            pq[parent] = pq[minIndex];
            pq[minIndex] = temp;
            parent = minIndex;
            leftchild = (2 * parent) + 1, rightchild = (2 * parent) + 2;
        }
        return minelement;
    }
};