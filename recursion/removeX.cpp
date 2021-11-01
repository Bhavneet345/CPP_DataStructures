#include<iostream>
#include<cstring>
using namespace std;

void remove(char input1[], char input2[], int current, int size)
{
    if(size == 0)
    {
        input2[current] = '\0';
        return;
    }
    if(input1[0] != 'x')
    {
        input2[current] = input1[0];
        current++;
    }
    remove(input1 + 1, input2, current, size - 1);
}

void removeX(char input[])
{
    char input2[1000];
    int current = 0;
    remove(input, input2, current, strlen(input));
    input[0] = '\0';
    strcpy(input, input2);
}

int main()
{
    char str[1000], new_str[1000];
    cin.getline(str, 1000);
    removeX(str);
    cout<<str;
    return 0;
}

