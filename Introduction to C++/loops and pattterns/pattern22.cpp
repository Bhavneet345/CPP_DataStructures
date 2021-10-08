#include<iostream>
using namespace std;

int main()
{
    int l = 6, m = 16, k = 13;

    for(int i = 1; i <= 5; i++)
    {
        if(i == 5)
        {
            for(int l = k; k >= 9; k--)
            {
                cout<<k<<" ";
            }
        }

        else
        {
             for(int j = 1; j <= 5; j++)
        {
            if(i == 1)
            {
                cout<<j<<" ";
            }

            else if(j == 1)
            {
                cout<<m;
                m -= 1;
            }

            else if(j == 5)
            {
                cout<<l;
                l -= 1;
            }

            else
            {
                cout<<"  ";
            }
        }
        
        }
        cout<<endl;
    }
}