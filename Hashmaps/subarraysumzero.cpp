#include<iostream>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int input[], int size)
{
    unordered_map<int, int>map;
    int sum = 0, ans = INT_MIN, temp = 0;
    for(int i = 0; i < size; i++)
    {
        sum += input[i];
        if(sum == 0)
        {
            ans = i + 1;
        }
        else if(map.find(sum) != map.end())
        {
            temp = abs(i - map[sum]);
            if(temp > ans)
            {
                ans = temp;
            }
        }
        map[sum] = i;
    }
    return ans;
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
    int count = lengthOfLongestSubsetWithZeroSum(arr, n);
    cout << count;
    return 0;
}