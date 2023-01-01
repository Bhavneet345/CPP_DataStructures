#include<iostream>
using namespace std;

bool ispermutation(char str1[], char str2[])
{
    int arr1[256] = {0};
    for(int i = 0; str1[i] != '\0'; i++)
    {
        int ascii = str1[i];
        arr1[ascii] += 1;
    }

    for(int i = 0; str2[i] != '\0'; i++)
    {
        int ascii = str2[i];
        arr1[ascii] -= 1;
    }

    for(int i = 0; i < 256; i++)
    {
        if(arr1[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str1[100], str2[100];
    cin>>str1>>str2;
    cout<<(ispermutation(str1, str2) ? "true" : "false");
    return 0;
}