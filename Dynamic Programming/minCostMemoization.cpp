#include<iostream>
using namespace std;

int minCostPath(int **input, int **saved, int x, int y, int m, int n)
{
    if(x == m - 1 && y == n - 1)
    {
        return input[x][y];
    }
    else if(x >= m || y >= n)
    {
        return INT_MAX;
    }
    else if(saved[x][y] != -1)
    {
        return saved[x][y];
    }
    int rightcost = minCostPath(input, saved, x, y + 1, m, n);
    int bottomcost = minCostPath(input, saved, x + 1, y, m, n);
    int diagonalcost = minCostPath(input, saved, x + 1, y + 1, m, n);
    int ans = min(rightcost, min(bottomcost, diagonalcost)) + input[x][y];
    saved[x][y] = ans;
    return ans;
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