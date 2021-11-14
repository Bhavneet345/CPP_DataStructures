#include<iostream>
using namespace std;

int getDigit(string input)
{
    int num;
    if(input.length() > 1)
    {
        num = input[0] - '0';
        num = num * 10;
        num = num + (input[1] - '0');
    }
    else
    {
        num = input[0] - '0';
    }
    return num;
}

void printAllcodes(string input, string output)
{
    if(input.empty())
    {
        cout<<output<<endl;
        return;
    }
    int i = getDigit(input.substr(0, 1));
    char element = i + 'a' - 1;
    printAllcodes(input.substr(1), output + element);
    if(input[1] != '\0')
    {
        int num = getDigit(input.substr(0, 2));
        if(num <= 26 && num >= 1)
        {
            element = num + 'a' - 1;
            printAllcodes(input.substr(2), output + element);
        }
    }
}

int main()
{
    string input, output = "";
    cin>>input;
    printAllcodes(input, output);
    return 0;
}