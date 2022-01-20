#include<iostream>
#include<queue>
using namespace std;

void runningMedian(int *input, int size)
{
    priority_queue<int>maxheap;
    priority_queue<int, vector<int>, greater<int> >minheap;
    for(int i = 0; i < size; i++)
    {
        if(maxheap.size() && input[i] > maxheap.top())
        {
            minheap.push(input[i]);
        }
        else
        {
            maxheap.push(input[i]);
        }
        int diff = minheap.size() - maxheap.size();
        if(abs(diff) > 1)
        {
            if(minheap.size() > maxheap.size())
            {
                maxheap.push(minheap.top());
                minheap.pop();
            }
            else
            {
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }
        int median;
        if((i + 1) % 2 == 0)
        {
            median = (maxheap.top() + minheap.top()) / 2;
        }
        else
        {
            if(minheap.size() > maxheap.size())
            {
                median = minheap.top();
            }
            else
            {
                median = maxheap.top();
            }
        }
        cout << median << " ";
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    runningMedian(input, n);
    return 0;
}