#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int num,rem,dec = 0;
    float i = 0.0;
    cin>>num;

    while(num != 0)
    {
        rem = num % 10;
        num = num / 10;
        dec = dec + (pow(2.0, i) * rem);
        i++;
    }

    cout<<dec;

    return 0;
}