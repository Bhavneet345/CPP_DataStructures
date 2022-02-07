#include<iostream>
#include<climits>
using namespace std;

int multiplicationHelper(int *arr, int start, int end, int **saved)
{
    if(start == end || start == end - 1)
    {
        return 0;
    }
    else if(saved[start][end] != -1)
    {
        return saved[start][end];
    }
    int minimum = INT_MAX;
    for(int k = start + 1; k <= end - 1; k++)
    {
        int ans1 = multiplicationHelper(arr, start, k, saved);
        int ans2 = multiplicationHelper(arr, k, end, saved);
        int ans3 = arr[start] * arr[k] * arr[end];
        int total = ans1 + ans2 + ans3;
        if(minimum > total)
        {
            minimum = total;
        }
    }
    saved[start][end] = minimum;
    return minimum;
}

int matrixChainMultiplication(int* arr, int n)
{
    int **saved = new int*[n + 1];
    for(int i = 0; i <= n; i++)
    {
        saved[i] = new int[n + 1];
        for(int j = 0; j <= n; j++)
        {
            if(i == j)
            {
                saved[i][j] = 0;
            }
            else if(i > j)
            {
                saved[i][j] = -1;
            }
            else if(i < j)
            {
                if(abs(i - j) == 1)
                {
                    saved[i][j] = 0;
                }
                else
                {
                    saved[i][j] = -1;
                }
            }
        }
    }
    return multiplicationHelper(arr, 0, n, saved);
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