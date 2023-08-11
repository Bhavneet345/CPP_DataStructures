#include<iostream>
using namespace std;

int arr[11][11];

bool ispossible(int n, int row, int column)
{
    //check the upper vertical column
    for(int i = row - 1; i >= 0; i--)
    {
        if(arr[i][column] == 1)
        {
            return false;
        }
    }

    //check the upper left diagonal
    for(int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(arr[i][j] == 1)
        {
            return false;
        }
    }

    //check the upper right diagonal
    for(int i = row - 1, j = column + 1; i >= 0 && j < n; i--, j++)
    {
        if(arr[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void nQueensHelper(int n, int rows)
{
    if(rows == n)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;   
    }
    for(int i = 0; i < n; i++)
    {
        if(ispossible(n, rows, i))
        {
            arr[rows][i] = 1;
            nQueensHelper(n, rows + 1);
            arr[rows][i] = 0;
        }
    }
    return;
}

void placeNqueens(int n)
{
    memset(arr, 0, 11 * 11 * sizeof(int));
    nQueensHelper(n, 0);
    return;
}

int main()
{
    int n;
    cin >> n;
    placeNqueens(n);
    return 0;
}