#include<iostream>
using namespace std;

string compressString(char str[])
{
    int k = 0, start = 0;
    char newstr[10000];
    while(str[start] != '\0')
    {
        int count  = 0;
        for(int j = start; str[j] != '\0'; j++)
        {
            if(str[j] == str[j + 1]) 
            {
                count++;
            }
            else
            {
                count = count  + 1;
                if(count >= 2)
                {
                    char ch = count + 48;
                    newstr[k] = str[start];
                    newstr[++k] = ch;
                    ++k;
                }
                else
                {
                    newstr[k] = str[start];
                    ++k;
                }
                start = j + 1;
                break;
            }
        }
    }
    newstr[k] = '\0';
    return newstr;
}

int main()
{
    char str[100];
    cin.getline(str, 100);
    string newstr = compressString(str);
    cout<<newstr;
    return 0;
}