#include<iostream>
using namespace std;

int main()
{
    int n_rows;
    cin>>n_rows;

    for(int i = 1; i <= n_rows; i++)
    {
        for(int j = 1; j <= n_rows; j++)
        {
            if(j == (n_rows- i) + 1)
            {
                cout<<"*";
            }
            else
            {
                cout<<(n_rows - j) + 1;
            }
        }
        cout<<endl;
    }
    return 0;
}