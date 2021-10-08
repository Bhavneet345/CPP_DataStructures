#include<iostream>
using namespace std;

int main()
{
    int num,rev=0,rem;

    cin>>num;

    while(num != 0)
    {
        rem = num % 10;
        num = num / 10;
        rev = rev * 10 + rem;
    }

    cout<<rev;

    return 0;

}