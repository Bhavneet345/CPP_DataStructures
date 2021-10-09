#include<iostream>
using namespace std;

int main()
{
    int num, num1, i, j;

    cout<<"Enter numbe of rows\n";
    cin>>num;

    for(i = 1; i <= num; i++)
    {
        for(int k = 1; k <= num - i; k++)
        {
            cout<<" ";
        }

        num1 = i;
        for(j = 1; j <= i; j++)
        {
            cout<<num1;
            num1++ ;
        }
        
        num1 = num1 - 2;

        for(int l = 1; l <= i - 1; l++)
        {
            cout<<num1;
            num1--;
        }
        
        cout<<endl;
    }
    return 0;
}