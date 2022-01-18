#include<iostream>
#include<vector>
using namespace std;

class maxpriority
{
    vector<int> pq;
    public:
    maxpriority()
    {}
    int getSize()
    {
        return pq.size();
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getmax()
    {
        return pq[0];
    }
    void insert(int element)
    {
        pq.push_back(element);
        int childindex = pq.size() - 1;
        int parent;
        while(childindex > 0)
        {
            parent = (childindex - 1) / 2;
            if(pq[parent] < pq[childindex])
            {
                int temp = pq[parent];
                pq[parent] = pq[childindex];
                pq[childindex] = temp;  
            }
            else
            {
                break;
            }
            childindex = parent;
        }
        return;
    }
    int removemax()
    {
        int maxelement = getmax();
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parent = 0, maxindex = 0;
        int leftchild = (2 * parent) + 1, rightchild = (2 * parent) + 2;
        while(leftchild < pq.size())
        {
            maxindex = parent;
            if(pq[maxindex] < pq[leftchild])
            {
                maxindex = leftchild;
            }
            if(rightchild < pq.size() && pq[maxindex] < pq[rightchild])
            {
                maxindex = rightchild;
            }
            if(maxindex == parent)
            {
                break;
            }
            int temp = pq[maxindex];
            pq[maxindex] = pq[parent];
            pq[parent] = temp;
            parent = maxindex;
            leftchild = (2 * parent) + 1, rightchild = (2 * parent) + 2;
        }
        return maxelement;
    }
};