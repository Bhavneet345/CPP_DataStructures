#include<iostream>
using namespace std;

void print2Darray(int arr[][100], int row, int col) // always pass the value of c - total columns....
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int arr[100][100], row, col;
    cin>>row>>col;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin>>arr[i][j];
        }
    }
    print2Darray(arr, row, col);
    return 0;
}