#include<iostream>
using namespace std;

void square_sequence()
{
    int arr[10][10] = {0}, top = 9, low = 0, n = 1;

    for(int i = 0; i < 5; i++,low++,top--)
    {
        for(int j = low; j <= top; j++,n++)
        {
            arr[i][j] = n;
        }

        for(int j = low+1; j <= top; j++,n++)
        {
            arr[j][top] = n;
        }

        for(int j = top - 1; j >=low; j--,n++)
        {
            arr[top][j] = n; 
        }

        for(int j = top-1; j > low; j--,n++)
        {
            arr[j][low] = n;
        }
    }
    for(int i = 0; i <= 9; i++)
    {
        for(int j = 0; j <= 9; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    square_sequence();
}