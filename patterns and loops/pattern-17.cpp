#include<iostream>
using namespace std;

int main()
{
    int num;

    cin>>num;

    for(int i = 1; i<= num; i++)
    {
        //loop to print spaces 
        for(int k = 1; k <= (num - i); k++)
        {
            cout<<" ";
        }

        //loop to print numbers
        for(int j = 1; j <= i; j++)
        {
            cout<<j;
        }

        //loop to print numbes in reverse order
        for(int m = i - 1; m >= 1; m--)
        {
                cout<<m;
        }
     cout<<endl;
    }
    return 0;
}