#include<iostream>
using namespace std;

void trimSpaces(char arr[])
{
    int j = 0;
    for(int i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] != ' ')
        {
            arr[j] = arr[i];
            j++;
        }
    }
    arr[j] = '\0';
}

int main()
{
    char arr[100];
    cin.getline(arr, 100);
    trimSpaces(arr);
    cout<<arr;
    return 0;
}