#include<iostream>
using namespace std;

void subSeq(string input, string output)
{
    if(input.empty())
    {
        cout<<output<<endl;
        return;
    }
    subSeq(input.substr(1), output + input[0]);
    subSeq(input.substr(1), output);
}

int main()
{
    string input, output = "";
    cin>>input;
    cout<<endl;
    subSeq(input, output);
    return 0;
}