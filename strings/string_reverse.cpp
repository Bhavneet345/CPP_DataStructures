#include<iostream>
using namespace std;

int length(char arr[])
{
    int count = 0;
    for(int i = 0; arr[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse(char arr[])
{
    int i = 0, j = length(arr) - 1;
    while(i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char arr[100];
    cin.getline(arr, 100);
    reverse(arr);
    cout<<"Reversed string is "<<arr;
    return 0;
}