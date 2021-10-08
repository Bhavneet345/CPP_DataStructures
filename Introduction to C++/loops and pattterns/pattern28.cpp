#include<iostream>
using namespace std;

int main()
{
    int rows = 5, col = 10, diff = 29, temp = 36;

    for(int i = 1; i <= rows; i++)
    {
        int k = temp;
        for(int j = 1; j <= col; j++)
        {
            if(i == 1)
            {
                cout<<j<<" ";
            }

            else
            {
                if(j <= i)
                {
                    cout<<k<<" ";
                    if(j != i)
                    {
                        k = k + diff;
                        diff -= 8;
                    }
                }

                else if(j <= col - i + 1)
                {
                    cout<<k<<" ";
                    if( k != col - i + 1)
                    {
                        k++;
                    }
                }

                else
                {
                    if (j - 1 == 5)
                    {
                        k = k - 1;
                        cout<<k<<" ";
                    }
                    else if(j - 1 == 6)
                    {
                        k = k - 9;
                        cout<<k<<" ";
                    }
                    else if(j - 1 == 7)
                    {
                        k = k - 17;
                        cout<<k<<" ";
                    }
                    else if(j - 1 == 8)
                    {
                        k = k - 25;
                        cout<<k<<" ";
                    }
                    else if(j - 1 == 9)
                    {
                        k = k - 33;
                        cout<<k;
                    }
                }
            }
        }
    }
    temp = temp - 1;
    cout<<endl;
}