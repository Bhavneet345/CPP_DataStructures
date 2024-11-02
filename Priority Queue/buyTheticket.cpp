#include<iostream>
#include<queue>
using namespace std;

int buyticket(int *input, int size, int k)
{
    int time = 0;
    queue<int>pending;
    priority_queue<int>maxheap;
    for(int i = 0; i < size; i++)
    {
        pending.push(i);
    }
    for(int i = 0; i < size; i++)
    {
        maxheap.push(input[i]);
    }
    while(!pending.empty())
    {
        int index = pending.front();
        pending.pop();
        if(input[index] >= maxheap.top())
        {
            time += 1;
            if(index == k)
            {
                break;
            }
            maxheap.pop();
        }
        else
        {
            pending.push(index);
        }
    }
    return time;
}

int main()
{
    int n, k;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    cin >> k;
    int time = buyticket(input, n, k);
    cout << time;
    return 0;
}