#include<iostream>
using namespace std;

int editDistance(string s, string t)
{
    int m = s.length(), n = t.length();
    int **saved = new int*[m + 1];
    for(int k = 0; k <= m; k++)
    {
        saved[k] = new int[n + 1];
    }
    for(int i = 0; i <= s.length(); i++)
    {
        for(int j = 0; j <= t.length(); j++)
        {
            saved[i][j] = -1;
        }
    }
    
    //filling for 1st row
    for(int i = 0; i <= t.length(); i++)
    {
        saved[0][i] = i;
    }

    //filling for first column
    for(int j = 0; j <= s.length(); j++)
    {
        saved[j][0] = j;
    }

    for(int i = 1; i <= s.length(); i++)
    {
        for(int j = 1; j <= t.length(); j++)
        {
            if(s[m - i] == t[n - j])
            {
                saved[i][j] = saved[i - 1][j - 1];
            }
            else
            {
                int insert = saved[i - 1][j];
                int deleteoperation = saved[i][j - 1];
                int replace = saved[i - 1][j - 1];
                saved[i][j] = min(insert, min(deleteoperation, replace)) + 1;
            }
        }
    }
    return saved[m][n];
}

int main()
{
    string input1, input2;
    cin >> input1 >> input2;
    cout << editDistance(input1, input2);
    return 0;
}