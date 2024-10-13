#include<iostream>
#include<unordered_map>
using namespace std;

int getPairsWithDifferenceK(int *input, int size, int k)
{
    unordered_map<int, int>map;
    int pairs = 0;
    for(int i = 0; i < size; i++)
    {
        int compliment = input[i] + k;
        pairs += map[compliment];
        if(k != 0)
        {
            compliment = input[i] - k;
            pairs += map[compliment];
        }
        map[input[i]] += 1;
    }
    cout << map[200] << endl;
    return pairs;
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    int count  = getPairsWithDifferenceK(arr, n, k);
    cout << count;
    return 0;
}