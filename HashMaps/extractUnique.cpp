#include<iostream>
#include<unordered_map>
using namespace std;

string uniqueChar(string input)
{
    unordered_map<char, int>map;
    string output = "";
    for(int i = 0; i < input.length(); i++)
    {
        if(map.find(input[i]) == map.end())
        {
            map[input[i]] += 1;
            output += input[i];
        }
    }
    return output;
}

int main()
{
    string input;
    cin >> input;
    string output = uniqueChar(input);
    cout << output;
    return 0;
}