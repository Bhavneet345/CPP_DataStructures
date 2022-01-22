#include<iostream>
#include<unordered_map>
using namespace std;

int pairSum(int *input, int size)
{
    unordered_map<int, int>map;
    int pairs = 0;
    for(int i = 0; i < size; i++)
    {
        if(!map.empty() && map.find(-input[i]) != map.end())
        {
            pairs += map[-input[i]];
        }
        map[input[i]] += 1;
    }
    return pairs;
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
    int count  = pairSum(arr, n);
    cout << count;
    return 0;
}