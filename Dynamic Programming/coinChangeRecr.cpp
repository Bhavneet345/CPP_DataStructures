#include<iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int start, int numDenominations, int value, int **saved)
{
    if(numDenominations == start || value == 0)
    {
        if(value == 0)
        {
            return 1;
        }
        return 0;
    }
    if(saved[start][value] != -1)
    {
        return saved[start][value];
    }
    int result = countWaysToMakeChange(denominations, start + 1, numDenominations, value, saved);
    if(value - denominations[start] >= 0)
    {
        result += countWaysToMakeChange(denominations, start, numDenominations, value - denominations[start], saved);
    }
    saved[start][value] = result;
    return saved[start][value];
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
    int **saved = new int*[value + 1];
    for(int i = 0; i < n; i++)
    {
        saved[i] = new int[value + 1];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= value; j++)
        {
            saved[i][j] = -1;
        }
    }
    cout << countWaysToMakeChange(denominations, 0, n, value, saved);
    return 0;
}