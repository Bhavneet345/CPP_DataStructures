#include<iostream>
using namespace std;

int maze[19][19];
int path[19][19];

void helper(int x, int y, int n)
{
    if(x == n - 1 && y == n - 1)
    {
        path[x][y] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << path[i][j] << " ";
            }
        }
        path[x][y] = 0;
        cout << endl;
        return;
    }
    if(x > n - 1 || y > n - 1)
    {
        return;
    }
    if(x < 0 || y < 0 || maze[x][y] == 0 || path[x][y] == 1)
    {
        return;
    }
    path[x][y] = 1;
    helper(x - 1, y, n);
    helper(x + 1, y, n);
    helper(x, y - 1, n);
    helper(x, y + 1, n);
    path[x][y] = 0;
    return;
}

void ratInMaze(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    memset(path, 0, 19 * 19 * sizeof(int));
    helper(0, 0, n);
    return;
}

int main()
{
    int n;
    cin >> n;
    ratInMaze(n);
    return 0;
}