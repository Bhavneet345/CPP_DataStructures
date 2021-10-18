#include<iostream>
using namespace std;

void removeConsecutiveduplicates(char str[])
{
    int j = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        char temp = str[i];
        for(int j = i + 1; str[j] != '\0'; j++)
        {
            if(str[j] == temp)
            {
                str[j] = ' ';
            }
            else
            {
                break;
            }
        }
    }
    j = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    cout<<str;
}

int main()
{
    char str[100];
    cin>>str;
    removeConsecutiveduplicates(str);
    return 0;
}
