#include<iostream>
using namespace std;

int length(char str[])
{
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse(char str[], int start, int len)
{
    int i = start, j = len - 1;
    for(i = start; i < j; i++)
    {
        int temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
}

void reverseStringwordwise(char str[])
{
    int count = 0;
    int len = length(str), start = 0, end = 0;
    reverse(str, start, len);
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i + 1] == ' ' || str[i + 1] == '\0')
        {
            end = i + 1;
            reverse(str, start, end);
            start = i + 2;
        }
    }
}

int main()
{
    char str[10000];
    cin.getline(str, 10000);
    reverseStringwordwise(str);
    cout<<str;
    return 0;
}