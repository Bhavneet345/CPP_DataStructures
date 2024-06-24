#include<iostream>
using namespace std;

int longestIncreasingSubsequence(int *arr, int n)
{
    int maximum = INT_MIN;
    int *saved = new int[n];
    saved[n - 1] = 1;
    for(int i = n - 2; i >= 0; i--)
    {
        int j;
        int length = INT_MIN;
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] < arr[j] && length < saved[j])
            {
                saved[i] = saved[j] + 1;
                length = saved[j];
            }
        }
        if(j == n && length == INT_MIN)
        {
            saved[i] = 1;
        }
        if(maximum < saved[i])
        {
            maximum = saved[i];
        }
    }
    return maximum;
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
    cout << longestIncreasingSubsequence(arr, n);
    return 0;
}