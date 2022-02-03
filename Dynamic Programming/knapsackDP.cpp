#include<iostream>
using namespace std;

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    int **saved = new int*[n + 1];
    for(int i = 0; i <= n; i++)
    {
        saved[i] = new int[maxWeight + 1];
    }
    // for element number == n;
    for(int j = 0; j <= maxWeight; j++)
    {
        saved[n][j] = 0;
    }
    //for maxweight == 0
    for(int i = 0; i <= n; i++)
    {
        saved[i][0] = 0;
    }
    int maxValue = INT_MIN;
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = 1; j <= maxWeight; j++)
        {
            int including = INT_MIN, excluding = INT_MIN;
            if(j - weights[i] >= 0)
            {
                including = values[i] + (saved[i + 1][j - weights[i]]);
            }
            excluding = saved[i + 1][j];
            saved[i][j] = max(including, excluding);
            if(maxValue < saved[i][j])
            {
                maxValue = saved[i][j];
            }
        }
    }
    return maxValue;
}

int main()
{
    int n, maxweight;
    cin >> n;
    int *weights = new int[n];
    int *values = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    for(int j = 0; j < n; j++)
    {
        cin >> values[j];
    }
    cin >> maxweight;
    cout << knapsack(weights, values, n, maxweight);
    return 0;
}