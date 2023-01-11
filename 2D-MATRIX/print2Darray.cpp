#include<iostream>
using namespace std; 

void print2Darray(int arr[][100], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = rows - i; j >= 1; j--)
        {
            for(int k = 0; k < cols; k++)
            {
                cout<<arr[i][k]<<" ";
            }
            cout<<endl;
        }
    }
}

int main()
{
    int arr[100][100], rows, cols;
    cin>>rows>>cols;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin>>arr[i][j];
        }
    }
    print2Darray(arr, rows, cols);

}