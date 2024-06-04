#include<iostream>
using namespace std;

int editDistance(string s, string t, int **saved)
{
    int m = s.length(), n = t.length();
    if(s.empty() || t.empty())
    {
        return max(m, n);
    }
    else if(saved[m][n] != -1)
    {
        return saved[m][n];
    }
    else if(s[0] == t[0])
    {
        saved[m][n] = editDistance(s.substr(1), t.substr(1), saved);
        return saved[m][n];
    }
    int insert = editDistance(s.substr(1), t, saved) + 1;
    int deleteoperation = editDistance(s, t.substr(1), saved) + 1;
    int replace = editDistance(s.substr(1), t.substr(1), saved) + 1;
    saved[m][n] = min(insert, min(deleteoperation, replace));
    return saved[m][n];
}

int main()
{
    string input1, input2;
    cin >> input1 >> input2;
    int i = input1.length(), j = input2.length();
    int **saved = new int*[i + 1];
    for(int k = 0; k <= i; k++)
    {
        saved[k] = new int[j + 1];
    }
    for(int i = 0; i <= input1.length(); i++)
    {
        for(int j = 0; j <= input2.length(); j++)
        {
            saved[i][j] = -1;
        }
    }
    cout << editDistance(input1, input2, saved);
    return 0;
}