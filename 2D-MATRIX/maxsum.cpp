#include<iostream>
#include<climits>
using namespace std;

void maxSum(int arr[][1000], int rows, int cols)
{
    int sum = INT_MIN, sum_row = 0, sum_col = 0, rowno = 0, colno = 0;
    bool isrow = true;
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            sum_row = sum_row + arr[i][j];
        }
        if(sum_row > sum)
        {
            rowno = i;
            sum = sum_row;
        }
        sum_row = 0;
    }
    sum_row = sum;
    for(int i = 0; i < cols; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            sum_col = sum_col + arr[j][i];
        }
        if(sum_col > sum)
        {
            isrow = false;
            colno = i;
            sum = sum_col;
        }
        sum_col = 0;
    }
    sum_col = sum;

    if(rows != 0)
    {
        if(isrow)
        {
            cout<<"row"<<" "<<rowno<<" "<<sum_row;
        }
        else
        {
            cout<<"column"<<" "<<colno<<" "<<sum_col;
        }
    }

    else
    {
        cout<<"row"<<" "<<rowno<<" "<<sum;
    }
}

int main()
{
    int arr[1000][1000], row, col;
    cin>>row>>col;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin>>arr[i][j];
        }
    }
    maxSum(arr, row, col);
    return 0;
}