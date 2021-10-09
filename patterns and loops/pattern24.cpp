#include<iostream>
using namespace std;

int main()
{
    int rows;

    cin>>rows;

    int n1 = (rows / 2) + 1;
    int n2 = rows - n1;

    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= rows; j++)
        {
            if(j == i || j == (rows - i + 1))
            {
                cout<<i;
            }

            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }

    int temp = n1 - 1;

    for(int i = n2; i <= rows; i++)
    {
        for(int j = 1; j <= rows; j++)
        {
            if(j == temp || j == (rows - temp) + 1)
            {
                cout<<temp;
            }

            else
            {
                cout<<" ";
            }
        }
        temp--;
        cout<<endl;
    }

    return 0;
}
