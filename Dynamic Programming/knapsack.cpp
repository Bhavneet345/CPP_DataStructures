#include<iostream>
using namespace std;

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    if(n == 0 || maxWeight == 0)
    {
        return 0;
    }
    int firstvalue = INT_MIN;
    if(maxWeight - weights[0] >= 0)
    {
        firstvalue = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]) + values[0];
    }
    int value = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    return max(firstvalue, value);
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