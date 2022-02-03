#include<iostream>
using namespace std;

int knapSack(int *weights, int *values, int n, int maxWeight, int **saved, int start)
{
    if(n == start || maxWeight == 0)
    {
        return 0;
    }
    else if(saved[start][maxWeight] != -1)
    {
        return saved[start][maxWeight];
    }
    int firstvalue = INT_MIN;
    if(maxWeight - weights[start] >= 0)
    {
        firstvalue = knapSack(weights, values, n, maxWeight - weights[start], saved, start + 1) + values[start];
    }
    int value = knapSack(weights, values, n, maxWeight, saved, start + 1);
    int ans = max(firstvalue, value);
    saved[start][maxWeight] = ans;
    return ans;
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
    int **saved = new int*[n + 1];
    for(int i = 0; i <= n; i++)
    {
        saved[i] = new int[maxweight + 1];
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= maxweight; j++)
        {
            saved[i][j] = -1;
        }
    }
    cout << knapSack(weights, values, n, maxweight, saved, 0);
    return 0;
}