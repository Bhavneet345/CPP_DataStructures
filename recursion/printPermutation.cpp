#include<iostream>
using namespace std;

void PrintPermutation(string input, string output)
{
    if(input.empty())
    {
        cout<<output<<endl;
        return;
    }
    string temp = "";
    for(int i = 0; i < input.length(); i++)
    {
        temp = "";
        for(int j = 0; j < input.length(); j++)
        {
            if(input[i] != input[j] || i != j)
            {
                temp = temp + input[j];
            }
        }
        PrintPermutation(temp, output + input[i]);
    }
}

int main()
{
    string input, output = "";
    cin>>input;
    PrintPermutation(input, output);
    return 0;
}