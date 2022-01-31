#include<iostream>
#include<cmath>
using namespace std;

int mod = (int)(pow(10, 9) + 7);

long long int minCostPath(int **input, int x, int y, int m, int n)
{
    if(x == m - 1 && y == n - 1)
    {
        return input[x][y];
    }
    if(x >= m || y >= n)
    {
        return INT_MAX;
    }
    long long int rightcost = minCostPath(input, x, y + 1, m, n);
    rightcost = (rightcost % mod) + input[x][y];
    long long int bottomcost = minCostPath(input, x + 1, y, m, n);
    bottomcost = (bottomcost % mod) + input[x][y];
    long long int diagonalcost = minCostPath(input, x + 1, y + 1, m, n);
    diagonalcost = (diagonalcost % mod) + input[x][y];
    long long int ans = min(rightcost, min(bottomcost, diagonalcost));
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **input = new int*[m];
    for(int i = 0; i < m; i++)
    {
        input[i] = new int[n];
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }
    cout << minCostPath(input, 0, 0, m, n);
    return 0;
}