#include<iostream>
using namespace std;

int main()
{
    int n_rows;
    cin>>n_rows;

    int r1 = n_rows / 2;

    for(int i = 1; i <= r1; i++)
    {
        for(int j = 1; j <= 2*i - 1; j++)
        {
            if(j%2 == 0)
            {
                cout<<"*";
            }
            else
            {
                cout<<i;
            }
        }
        cout<<endl;
    }

    int temp = 1;

    for(int i = r1; i >= 1; i--)
    {
        for(int j = 1; j <= n_rows - temp; j++)
        {
            if(j%2 == 0)
            {
                cout<<"*";
            }

            else
            {
                cout<<i;
            }
        }
        cout<<endl;
        temp += 2;
    }
    return 0;
}