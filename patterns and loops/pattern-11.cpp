#include<iostream>
using namespace std;

int main()
{
    int num,num1=1,i,j;
    cout<<"Enter number of rows\n";
    cin>>num;

    for(i = 1; i <= num; i++)
    {
        for(j = 1; j <= i; j++)
        {
            cout<<num1;
            num1++;
        }
        cout<<endl;
    }
    return 0;
}