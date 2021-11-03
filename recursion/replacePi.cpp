#include<iostream>
#include<cstring>
using namespace std;

void replacePi(char input[])
{
    if(input[0] == '\0')
    {
        return;
    }
    else if(input[0] == 'p' && input[1] == 'i')
    {
        for(int i = 1; i <= 2; i++)
        {
            for(int j = strlen(input) + 1; j > 0; j--)
            {
                input[j] = input[j - 1];
            }
        }
        input[0] = 48 + 3;
        input[1] = '.';
        input[2] = 48 + 1;
        input[3] = 48 + 4;   
    }
    replacePi(input + 1);
}

int main()
{
    char input[100];
    cin>>input;
    replacePi(input);
    cout<<"New string "<<input;
    return 0;
}