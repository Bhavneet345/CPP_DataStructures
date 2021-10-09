#include<iostream>
using namespace std;

int main()
{
    int n_rows,temp = 1;
    cin>>n_rows;

    for(int i = 0; i < n_rows; i++)
    {
        for(int j = 0; j <= n_rows - i; j++)
        {
            cout<<" ";
        }
        temp = 1;
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || i == 0)
            {
                cout<<temp<<" ";
            }
            else
            {
                temp = temp * (i - j + 1) / j;
                cout<<temp<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}








