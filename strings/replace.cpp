#include<iostream>
using namespace std;

void replacecharacter(char arr[], char old_char, char new_char)
{
    for(int i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] == old_char)
        {
            arr[i] = new_char;
        }
    }
}

int main()
{
    char str[100], c1, c2;
    cin>>str>>c1>>c2;
    replacecharacter(str, c1, c2);
    cout<<str;
    return 0;
}
