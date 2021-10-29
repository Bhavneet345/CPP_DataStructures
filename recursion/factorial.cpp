#include<iostream>
using namespace std;

int factorial(int num)
{
   if(num == 0)
   {
       return 1;
   }
   int output = factorial(num - 1);
   return num * output;
}

int main()
{
    int num;
    cin>>num;
    int output =  factorial(num);
    cout<<"Factorial is "<<output;
    return 0;
}