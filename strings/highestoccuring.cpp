#include<iostream>
#include<climits>
using namespace std;

char highestOccurringChar(char str[])
{
    int arr[256] = {0}, count = 0;
    char ans;
    for(int i = 0; str[i] != '\0'; i++)
    {
        int ascii = str[i];
        arr[ascii]  = arr[ascii] + 1; 
    }

    ans = str[0];
    count = arr[(int)ans];
    for(int i = 1; str[i] != '\0'; i++)
    {
        if(count < arr[(int)str[i]])
        {
            ans = str[i];
            count = arr[(int)str[i]];
        }
    }
    return ans;
}

int main()
{
    char str[100],highest;
    cin.getline(str, 100);
    highest = highestOccurringChar(str);
    cout<<highest;
    return 0;
}