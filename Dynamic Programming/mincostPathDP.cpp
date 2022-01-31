#include<iostream>
using namespace std;

int minCostPath(int **input, int **saved, int x, int y, int m, int n)
{
    int rightcost = INT_MAX, bottomcost = INT_MAX, diagonalcost = INT_MAX;
    saved[m - 1][n - 1] = input[m - 1][n - 1];
    for(int i = m - 1; i >= 0; i--)
    {
        for(int j = n - 1; j >= 0; j--)
        {
            rightcost = INT_MAX, bottomcost = INT_MAX, diagonalcost = INT_MAX;
            int rightx = INT_MAX, righty = INT_MAX;
            int bottomx = INT_MAX, bottomy = INT_MAX;
            int diagonalx = INT_MAX,diagonaly = INT_MAX;
            if(j < n - 1)
            {
                rightx = i, righty = j + 1;
            }
            if(i < m - 1)
            {
                bottomx = i + 1, bottomy = j;
            }
            if(i < m - 1 && j < n - 1)
            {
                diagonalx = i + 1,diagonaly = j + 1;
            }
            if(rightx != INT_MAX && righty != INT_MAX)
            {
                rightcost = saved[rightx][righty];
            }
            if(bottomx != INT_MAX && bottomy != INT_MAX)
            {
                bottomcost = saved[bottomx][bottomy];
            }
            if(diagonalx != INT_MAX && diagonaly != INT_MAX)
            {
                diagonalcost = saved[diagonalx][diagonaly];
            } 
            if(i != m - 1 || j != n - 1)
            {
                saved[i][j] = min(rightcost, min(bottomcost, diagonalcost)) + input[i][j];
            }
        }
    }
    return saved[0][0];
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **input = new int*[m];
    int **saved = new int*[m];
    for(int i = 0; i < m; i++)
    {
        input[i] = new int[n];
        saved[i] = new int[n];
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> input[i][j];
            saved[i][j] = -1;
        }
    }
    cout << minCostPath(input, saved, 0, 0, m, n);
    return 0;
}