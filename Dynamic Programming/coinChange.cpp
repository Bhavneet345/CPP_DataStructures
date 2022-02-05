#include<iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
    int **saved = new int*[numDenominations + 1];
    for(int i = 0; i <= numDenominations; i++)
    {
        saved[i] = new int[value + 1];
    }
    // filling for value = 0
    for(int i = 0; i <= numDenominations; i++)
    {
        saved[i][0] = 0;
    }
    // filling for start == numdenominations
    for(int i = 0; i <= value; i++)
    {
        saved[numDenominations][i] = 0;
    }
    for(int i = numDenominations - 1; i >= 0; i--)
    {
        for(int j = 0; j <= value; j++)
        {
            if(denominations[i] > j)
            {
                saved[i][j] = 0;
            }
            else if(denominations[i] == j)
            {
                saved[i][j] = 1;
            }
            else
            {
                int sum = 0;
                int maxpossible = j / denominations[i];
                for(int k = 1; k <= maxpossible; k++)
                {
                    int temp = j - (k * denominations[i]);
                    if(temp == 0)
                    {
                        sum += 1;
                        break;
                    }
                    for(int j = i + 1; j <= numDenominations; j++)
                    {
                        sum += saved[j][temp];
                    }
                }
                saved[i][j] = sum;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i <= numDenominations; i++)
    {
        sum += saved[i][value];
    }
    return sum;
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