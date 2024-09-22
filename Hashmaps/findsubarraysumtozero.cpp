#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int input[], int n)
{
    int count = 0;
    int sum = 0;
    int len = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        count = 0;
        sum = input[i];
        int j = i + 1;
        while(j < n && sum != 0)
        {
            sum += input[j];
            ++j;
            ++count;
        }
        if(sum == 0 && count > len)
        {
            len = count + 1;
        }
    }
    return len;
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