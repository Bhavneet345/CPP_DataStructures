#include<iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int **dp = new int*[value + 1];
    for(int i = 0; i <= value; i++)
    {
        dp[i] = new int[numDenominations];
    }
    //filling for value = 0;
    for(int i = 0; i <= numDenominations - 1; i++)
    {
        dp[0][i] = 1;
    }
    for(int i = 1; i <= value; i++)
    {
        for(int j = 0; j < numDenominations; j++)
        {
            int x = (i - denominations[j] >= 0) ? dp[i - denominations[j]][j] : 0;
            int y = (j >= 1) ? dp[i][j - 1] : 0;
            dp[i][j] = x + y;
        }
    }
    return dp[value][numDenominations - 1];
}

int main()
{
    int n;
    cin >> n;
    int *denominations = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> denominations[i];
    }
    int value;
    cin >> value;
    cout << countWaysToMakeChange(denominations, n, value);
    return 0;
}