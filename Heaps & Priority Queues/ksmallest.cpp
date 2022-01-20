#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> kSmallest(int *input, int size, int k)
{
    priority_queue<int> maxheap;
    vector<int> res;
    for(int i = 0; i < k; i++)
    {
        maxheap.push(input[i]);
    }
    for(int i = k; i < size; i++)
    {
        if(input[i] < maxheap.top())
        {
            maxheap.pop();
            maxheap.push(input[i]);   
        }
    }
    while(!maxheap.empty())
    {
        res.push_back(maxheap.top());
        maxheap.pop();
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int *input = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    vector<int> res = kSmallest(input, n, k);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}