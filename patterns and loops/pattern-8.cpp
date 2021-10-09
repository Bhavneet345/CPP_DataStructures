#include<iostream>
using namespace std;

int main()
{
    int i,j,num;
    cout<<"Enter number of rows\n";
    cin>>num;

    for(i = 1; i <= num; i++)
    {
        for(j = num; j >= 1; j--)
        {
            cout<<j;
        }
    cout<<endl;
    }
}