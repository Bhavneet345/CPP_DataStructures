#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

string minlengthword(char str[])
{
    int minlength = INT_MAX, templength = 0, start = 0, end = 0, pos = 0;
    char minword[1000];
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ')
        {
            templength++;
        }
        else
        {
            if(templength < minlength)
            {
                pos = 0;
                minlength = templength;
                for(int j = start; j < i ; j++)
                {
                    minword[pos] = str[j];
                    pos++;
                }
                minword[pos] = '\0';
            }
            templength = 0;
            start = i + 1;
        }
    }
    if(templength < minlength)
    {
        pos = 0;
        for(int j = start; str[j] != '\0' ; j++)
        {
            minword[pos] = str[j];
            pos++;
        }
        minword[pos] = '\0';
    }
    return minword;
}

int main()
{
    char str[10000];
    cin.getline(str, 10000);
    string output = minlengthword(str);
    cout<<output;
    return 0;
}