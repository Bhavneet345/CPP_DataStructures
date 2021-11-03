#include<iostream>
#include<cstring>
using namespace std;

void pairStar(char input[])
{
    if(input[0] == '\0')
    {
        return;
    }
    if(input[0] == input[1])
    {
        for(int i = strlen(input) + 1; i > 0; i--)
        {
            input[i] = input[i - 1];
        }
        input[1] = '*';
    }
    pairStar(input + 1);
}

int main()
{
    char input[100];
    cin>>input;
    pairStar(input);
    cout<<"New string "<<input;
    return 0;
}