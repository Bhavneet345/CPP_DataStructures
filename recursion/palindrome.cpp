#include<iostream>
#include<cstring>
using namespace std;

bool helper(char input[], int start, int end)
{
    bool ispalindrome = true;
    if(input[start] != input[end])
    {
        return false;
    }
    if(start < end)
    {
        return helper(input, start + 1, end - 1);
    }
    return ispalindrome;
}

bool checkPalindrome(char input[]) {
    int start = 0, end = strlen(input) -1;
    if(strlen(input) == 1)
    {
        return true;
    }
    else
    {
        return helper(input, start, end);
    }
}

int main()
{
    char input[100];
    cin>>input;
    if(checkPalindrome(input))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}
