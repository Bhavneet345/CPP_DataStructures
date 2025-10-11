#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> kLargest(int *input, int size, int k)
{
    vector<int> res;
    priority_queue<int, vector<int>, greater<int> > minheap;
    for(int i = 0; i < k; i++)
    {
        minheap.push(input[i]);
    }
    for(int i = k; i < size; i++)
    {
        if(input[i] > minheap.top())
        {
            minheap.pop();
            minheap.push(input[i]);
        }
    }
    while(!minheap.empty())
    {
        res.push_back(minheap.top());
        minheap.pop();
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
    vector<int> res = kLargest(input, n, k);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
