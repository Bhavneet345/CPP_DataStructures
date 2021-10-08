#include<iostream>
using namespace std;

int main()
{
    int num,i,j;
    cin>>num;

    for(i = num; i>=1; i--)
    {
        for(j = i; j >= 1; j--)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}