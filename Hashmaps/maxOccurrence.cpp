#include<iostream>
#include<unordered_map>
using namespace std;

int highestFrequency(int *input, int size)
{
    int ans, max = INT_MIN;
    unordered_map<int, int>map;
    for(int i = 0; i < size; i++)
    {
        map[input[i]] += 1;
    }
    for(int i = 0; i < size; i++)
    {
        if(map[input[i]] > max)
        {
            max = map[input[i]];
            ans = input[i];
        }
    }
    return ans;
}

int main()
{
    int n, *input;
    cin >> n;
    input = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int ans = highestFrequency(input, n);
    cout << ans;
    return 0;
}