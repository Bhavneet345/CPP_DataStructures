#include<iostream>
using namespace std;

int main()
{
    int num,i,j;
    cin>>num;

    for(i = 1; i <= num; i++)
    {
        char alpha = 'A' + (i - 1);
        for(j = 1; j <= num; j++)
        {
            cout<<char(alpha + j - 1);
        }
        cout<<endl;
    }

    return 0;
}