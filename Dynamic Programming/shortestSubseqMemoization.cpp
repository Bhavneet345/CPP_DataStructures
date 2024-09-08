#include<iostream>
using namespace std;

int solve(string s, string v, int siA, int siB, int **saved)
{
    if(siB == v.length())
    {
        return 1;
    }
    if(siA == s.length())
    {
        return 1001;
    }
    if(saved[siA][siB] != -1)
    {
        return saved[siA][siB];
    }
    int ans1 = solve(s, v, siA + 1, siB, saved);
    int index = -1;
    for(int i = siB; i < v.length(); i++)
    {
        if(s[siA] == v[i])
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        return 1;
    }
    int ans2 = solve(s, v, siA + 1, index + 1, saved) + 1;
    if(ans1 > ans2)
    {
        saved[siA][siB] = ans2;
    }
    else
    {
        saved[siA][siB] = ans1;
    }
    return saved[siA][siB];
}

int main()
{
    string s, v;
    cin >> s >> v;
    int m = s.length(), n = v.length();
    int **saved = new int*[m];
    for(int i = 0; i < m; i++)
    {
        saved[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            saved[i][j] = -1;
        }
    }
    cout << solve(s, v, 0, 0, saved);
    return 0;
}