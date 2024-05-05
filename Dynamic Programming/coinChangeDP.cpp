#include<iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int saved[numDenominations][value + 1];
    for(int i = 0; i < numDenominations; i++)
    {
        saved[i][0] = 1;
    }
    for(int i = numDenominations - 1; i >= 0; i--)
    {
        for(int j = 1; j <= value; j++)
        {
            int count1 = 0;
            if(i != numDenominations - 1)
            {
                count1 = saved[i + 1][j];
            }
            int count2 = 0;
            if(j - denominations[i] >= 0)
            {
                count2 = saved[i][j - denominations[i]];
            }
            saved[i][j] = count1 + count2;
        }
    }
    return saved[0][value];
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