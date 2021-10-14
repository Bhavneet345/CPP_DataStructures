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

bool isPalindrome(char arr[])
{
    int len = length(arr);
    int i = 0, j = len - 1;
    while(i < j)
    {
        if(arr[i] != arr[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    char str[100];
    cin>>str;
    bool palindrome = isPalindrome(str);
    cout<<(palindrome?"true":"false");
    return 0;
}

