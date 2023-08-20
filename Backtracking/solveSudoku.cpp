#include<iostream>
using namespace std;

int board[9][9];

bool isEmpty(int &row, int &column)
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == 0)
            {
                row = i;
                column = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int row, int column, int choosen)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[row][i] == choosen)
        {
            return false;
        }
    }
    for(int i = 0; i < 9; i++)
    {
        if(board[i][column] == choosen)
        {
            return false;
        }
    }
    int columnfactor = column - (column % 3);
    int rowfactor = row - (row % 3);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[rowfactor + i][columnfactor + j] == choosen){
                return false;
            }
        }
    }
    return true;
}


bool solveSuodku()
{
    int rowno, columnno;
    if(!isEmpty(rowno, columnno))
    {
        return true;
    }
    for(int i = 1; i <= 9; i++)
    {
        if(isSafe(rowno, columnno, i))
        {
            board[rowno][columnno] = i;
            if(solveSuodku())
            {
                return true;
            }
            board[rowno][columnno] = 0;
        }
    }
    return false;
}

int main()
{
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cin >> board[i][j]; 
        }
    }

    // for(int i = 0; i < 9; i++)
    // {
    //     string s;
    //     cin >> s;
    //     for(int j = 0; j < 9; j++)
    //     {
    //         board[i][j] = s[j] - '0';   
    //     }
    // }
    solveSuodku();
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}