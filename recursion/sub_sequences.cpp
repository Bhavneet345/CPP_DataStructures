#include<iostream>
#include<cmath>
using namespace std;

int subsequence(string input, string output[])
{
    if(input.empty())
    {
        output[0] = " ";
        return 1;
    }
    int smalloutput = subsequence(input.substr(1), output);
    for(int i = 0; i < smalloutput; i++)
    {
        output[i + smalloutput] = input[0] + output[i];
    }
    return 2 * smalloutput;
}

int main()
{
    string str;
    cin>>str;
    int size = pow(2, str.size());
    string *output = new string[size];
    int count = subsequence(str, output);
    for(int i = 0; i < count; i++)
    {
        cout<<output[i]<<" ";
    }
    return 0;
}