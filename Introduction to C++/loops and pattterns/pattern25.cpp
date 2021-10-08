#include<iostream>
using namespace std;

int main()
{
    int n_rows=10,temp=0;

    for(int i = 1; i <= n_rows; i++)
    {
        int k = (n_rows - i) + 1;
        for(int j = 1; j<=i; j++)
        {
            if(j == i)
            {
                cout<<temp;
            }
            else
            {
                cout<<k;
                k++;   
            }
        }

        int n = n_rows - 1;
        for(int j = 1; j <= i -1; j++)
        {
            cout<<n;
            n--; 
        }
        cout<<endl;
    }

    return 0;
}