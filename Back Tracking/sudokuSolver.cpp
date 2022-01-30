#include<iostream>
#include<vector>
using namespace std;

int board[9][9];

bool returnSpace(int &row, int &column)
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

void fillOptions(vector<int> &options, int row, int column)
{
    // check for row
    for(int i = 0; i < 9; i++)
    {
        options.push_back(board[row][i]);
    }

    // check for column
    for(int i = 0; i < 9; i++)
    {
        options.push_back(board[i][column]);
    }

    //check for matrix
    int rowfactor = row - (row % 3);
    int columnfactor = column - (column % 3);
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            options.push_back(board[i + rowfactor][j + columnfactor]);
        }
    }
    return;
}

vector<int> filterOptions(vector<int> options)
{
    vector<int> res;
    for(int i = 1; i <= 9; i++)
    {
        int j;
        for(j = 0; j < options.size(); j++)
        {
            if(options[j] == i)
            {
                break;
            }
        }
        if(j == options.size())
        {
            res.push_back(i);
        }
    }
    return res;
}

bool canSolveSuduko()
{
    int row, column;
    bool isempty = returnSpace(row, column);
    if(!isempty)
    {
        return true;
    }
    vector<int> options;
    fillOptions(options, row, column);
    options = filterOptions(options);
    for(int i = 0; i < options.size(); i++)
    {
        board[row][column] = options[i];
        if(canSolveSuduko() == true)
        {
            return true;
        }
        board[row][column] = 0;
    }
    return false;
}

int main()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> board[i][j]; 
        }
    }
    if(canSolveSuduko())
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}