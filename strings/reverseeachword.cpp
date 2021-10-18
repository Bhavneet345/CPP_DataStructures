#include<iostream>
using namespace std;

void reverse(char str[], int start, int end)
{
    end = end - 1;
    while(start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseEachword(char str[])
{
    int start = 0, end = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i + 1] == ' ' || str[i + 1] == '\0')
        {
            end = i + 1;
            reverse(str, start, end);
            start = i + 2;
        }
    }
    cout<<str;
}

int main()
{
    char str[100];
    cin.getline(str, 100);
    reverseEachword(str);
    return 0;
}