#include<iostream>
using namespace std;

int main()
{
    int rows;
    cin>>rows;

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= (rows - i + 1); j++)
        {
            cout<<j;
        }

        for(int j = 2; j <= i; j++)
        {
            cout<<"*";
        }

        for(int j = 2; j <= i; j++)
        {
            cout<<"*";
        }
            
        for(int j = (rows - i + 1); j >= 1; j--)
        {
            cout<<j;
        }
        cout<<"\n";   
    }
    return 0;
}