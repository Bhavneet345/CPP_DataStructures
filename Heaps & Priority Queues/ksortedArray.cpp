#include<iostream>
#include<queue>
using namespace std;

void kSortedarray(int *input, int size, int k)
{
    priority_queue<int> maxheap;
    for(int i = 0; i < k; i++)
    {
        maxheap.push(input[i]);
    }
    int j = 0;
    for(int i = k; i < size; i++, j++)
    {
        input[j] = maxheap.top();
        maxheap.pop();
        maxheap.push(input[i]);
    }
    while(!maxheap.empty())
    {
        input[j] = maxheap.top();
        maxheap.pop();
        j++;
    }
    return;
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
    kSortedarray(input, n, k);
    for(int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}