#include<iostream>
using namespace std;

int maze[19][19], path[19][19];

void printPath(int startrow, int startcolumn, int n)
{
    if(startrow == n - 1 && startcolumn == n - 1)
    {
        path[startrow][startcolumn] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << path[i][j] << " ";
            }
        }
        path[startrow][startcolumn] = 0;
        cout << endl;
        return;
    }
    if(startrow > 0 && path[startrow - 1][startcolumn] != 1 && maze[startrow - 1][startcolumn] != 0)
    {
        path[startrow][startcolumn] = 1;
        printPath(startrow - 1, startcolumn, n);
        path[startrow][startcolumn] = 0;
    }
    if(startrow < n - 1 && path[startrow + 1][startcolumn] != 1 && maze[startrow + 1][startcolumn] != 0)
    {
        path[startrow][startcolumn] = 1;
        printPath(startrow + 1, startcolumn, n);
        path[startrow][startcolumn] = 0;
    }
    if(startcolumn > 0 && path[startrow][startcolumn - 1] != 1 && maze[startrow][startcolumn -1] != 0)
    {
        path[startrow][startcolumn] = 1;
        printPath(startrow, startcolumn - 1, n);
        path[startrow][startcolumn] = 0;
    }
    if(startcolumn < n - 1 && path[startrow][startcolumn + 1] != 1 && maze[startrow][startcolumn + 1] != 0)
    {
        path[startrow][startcolumn] = 1;
        printPath(startrow, startcolumn + 1, n);
        path[startrow][startcolumn] = 0;
    }
    return; 
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    } 
    memset(path, 0, 19 * 19 * sizeof(int));
    printPath(0, 0, n);
    return 0;
}