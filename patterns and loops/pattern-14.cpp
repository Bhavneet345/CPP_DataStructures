#include<iostream>
using namespace std;

int main()
{
    int num,i,j;

    cout<<"Enter number of rows\n";
    cin>>num;

    for(i = 1; i <= num; i++)
    {
        for(int k = 1; k <= num - i; k++)
        {
            cout<<" ";
        }      

        for(j = 1; j <= i; j++)
        {
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}