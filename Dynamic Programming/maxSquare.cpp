#include<iostream>
using namespace std;

int checkMaxSquarePossible(int **arr, int m, int n)
{
    int **dp = new int*[m];
    int maximum = 0;
    for(int i = 0; i < m; i++)
    {
        dp[i] = new int[n];
    }

    //filling firstColumn
    for(int i = 0; i < m; i++)
    {
        if(arr[i][0] == 0)
        {
            dp[i][0] = 1;
            maximum = 1;
            continue;
        }
        dp[i][0] = 0;
    }

    //filling firstRow
    for(int i = 0; i < n; i++)
    {
        if(arr[0][i] == 0)
        {
            dp[0][i] = 1;
            maximum = 1;
            continue;
        }
        dp[0][i] = 0;
    }
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(arr[i][j] != 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1;
                if(dp[i - 1][j - 1] != 0 && dp[i - 1][j] != 0 && dp[i][j - 1] != 0)
                {
                    dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
            if(maximum < dp[i][j])
            {
                maximum = dp[i][j];
            }
        }
    }
    return maximum;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **arr = new int*[m];
    for(int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << checkMaxSquarePossible(arr, m, n);
    return 0;
}