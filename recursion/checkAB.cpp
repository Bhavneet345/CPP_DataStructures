#include<iostream>
using namespace std;

bool checkAB(char input[], int start)
{
    if(input[start] == '\0')
    {
        return true;
    }
    if(input[start] != 'a')
    {
        return false;
    }
    if(input[1] != '\0' || input[2] != '\0')
    {
        if(input[1] == 'b' && input[2] == 'b')
        {
            return checkAB(input, start + 3);
        }
    }
    return(input, start + 1);
}

int main()
{
    char input[100];
    cin>>input;
    bool correct = checkAB(input, 0);
    if(correct)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}