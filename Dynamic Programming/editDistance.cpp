#include<iostream>
using namespace std;

int editDistance(string s, string t)
{
    if(s.empty() || t.empty())
    {
        return max(s.length(), t.length());
    }
    if(s[0] == t[0])
    {
        return editDistance(s.substr(1), t.substr(1));
    }
    int insert = editDistance(s.substr(1), t) + 1;
    int deleteoperation = editDistance(s, t.substr(1)) + 1;
    int replace = editDistance(s.substr(1), t.substr(1)) + 1;
    return min(insert, min(deleteoperation, replace));
}

int main()
{
    string input1, input2;
    cin >> input1 >> input2;
    cout << editDistance(input1, input2);
    return 0;
}