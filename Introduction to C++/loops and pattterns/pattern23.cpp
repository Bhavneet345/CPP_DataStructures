#include<iostream>
using namespace std;

int main()
{
    int rows;
    cin >> rows;

    int n1 = (rows / 2) + 1;
    int n2 = rows - n1;

    for(int i = 1; i <= n1 ; i++)
    {
        for(int j = 1; j <= n1 - i ; j++)
        {
            cout<<" ";
        }

        for(int j = 1; j <= (2 *i - 1); j++)
        {
            cout<<j;
        }
        cout<<endl;
    }

    for(int i = 1; i <= n2; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout<<" ";
        }

        for(int j = 1; j <= rows - (2*i); j++)
        {
            cout<<j;
        }
        cout<<endl;
    }

    return 0;
}