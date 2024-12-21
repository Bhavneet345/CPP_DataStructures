#include<iostream>
#include<queue>
using namespace std;

int kthLargest(int *input, int size, int k)
{
    priority_queue<int, vector<int>, greater<int> > minheap;
    for(int i = 0; i < k; i++)
    {
        minheap.push(input[i]);
    }
    for(int i = k; i < size; i++)
    {
        if(minheap.top() < input[i])
        {
            minheap.pop();
            minheap.push(input[i]);
        }
    }
    return minheap.top();
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
    int res = kthLargest(input, n, k);
    cout << res;
    return 0;
}
