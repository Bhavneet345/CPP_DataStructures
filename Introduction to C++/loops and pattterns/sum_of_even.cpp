#include<iostream>
using namespace std;

int main()
{
    int num; //number till the which even numbers have to be printed// 
    int i = 1;
    int sum = 0;

    cout<<"Enter the upper range of the numbers\n";
    cin>>num;

    while(i <= num)
    { 
        if(i % 2 == 0)
        {
            sum = sum + i;
        }
        
        i = i + 1;
    }

    cout<<"The sum is:"<<sum;

    return 0;
}