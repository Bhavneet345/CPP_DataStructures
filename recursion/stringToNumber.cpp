#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int returnNum(char input[], int length)
{
    if(length > 0)
    {
        int num = input[0];
        num = num - 48;
        return (num * pow(10, length - 1)) + returnNum(input + 1, length - 1);
    }
    return 0;
}

int stringToNumber(char input[]) 
{
    int num = returnNum(input, strlen(input));
    return num;
}

int main()
{
    char input[100];
    cin>>input;
    int num = stringToNumber(input);
    cout<<"The number is "<<num;
    return 0;
}