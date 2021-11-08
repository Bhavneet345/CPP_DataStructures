#include<iostream>
using namespace std;

int keypad(int num, string output[], string mapping[])
{
    if(num <= 1)
    {
        output[0] = "";
        return 1;
    }
    string temp[5000];
    int smalloutput = keypad(num / 10, temp, mapping);
    int rem = num % 10, len = mapping[rem].size();
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < smalloutput; j++)
        {
            output[j + (i * smalloutput)] = temp[j] + mapping[rem][i];
        }
    }
    return smalloutput * len;
}
int main()
{
    int num;
    cin>>num;
    string *output = new string[10000];
    string help[1000];
    string mapping[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int count = keypad(num, output, mapping);
    for(int i = 0; i < count; i++)
    {
        cout<<output[i]<<" ";
    }
   return 0;
}