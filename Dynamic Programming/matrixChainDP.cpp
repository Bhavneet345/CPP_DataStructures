#include<iostream>
#include<climits>
using namespace std;

int matrixChainHelper(int *arr, int n)
{
    int **dp = new int*[n + 1];
    for(int i = 0; i <= n; i++)
    {
        dp[i] = new int[n + 1];
    }
    for(int i = 0; i <= n; i++)
    {
        dp[n][i] = 0;
    }
    int start, end;
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 0; j <= n; j++)
        {
            start = i, end = j;
            if(start >= end || abs(start - end) == 1)
            {
                dp[start][end] = 0;
                continue;
            }
            int minimum = INT_MAX;
            for(int k = start + 1; k <= end - 1; k++)
            {
                int ans = dp[start][k];
                ans += dp[k][end];
                ans += arr[start] * arr[k] * arr[end];
                if(minimum > ans){
                    minimum = ans;
                }
            }    
            dp[start][end] = minimum;      
        }
    }
    return dp[0][n];
}

int matrixChainMultiplication(int* arr, int n)
{
    return matrixChainHelper(arr, n);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for(int i = 0; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << matrixChainMultiplication(arr, n);
    return 0;
}