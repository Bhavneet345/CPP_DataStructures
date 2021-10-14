#include<iostream>
using namespace std;

int length(char arr[])
{
    int len = 0;
    for(int i = 0; arr[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

int main()
{
    char name[100];
    int len = 0;
    cout<<"Enter the string\n";
    cin>>name;
    cout<<"Length is "<<length(name);
    return 0;
}