#include<iostream>
using namespace std;

int LCS(string input1, string input2, int **savedseq)
{
    if(input1.empty() || input2.empty())
    {
        return 0;
    }
    int i = input1.length() - 1, j = input2.length() - 1;
    if(savedseq[i][j] != -1)
    {
        return savedseq[i][j];
    }
    else if(input1[0] == input2[0])
    {
        int ans = LCS(input1.substr(1), input2.substr(1), savedseq);
        savedseq[i][j] = ans + 1;
        return ans + 1;
    }
    int case1 = LCS(input1.substr(1), input2, savedseq);
    int case2 = LCS(input1, input2.substr(1), savedseq);
    int ans = max(case1, case2);
    savedseq[i][j] = ans;
    return ans;
}

int main()
{
    string input1, input2;
    cin >> input1 >> input2;
    int i = input1.length(), j = input2.length();
    int **saved = new int*[i];
    for(int k = 0; k < i; k++)
    {
        saved[k] = new int[j];
    }
    for(int i = 0; i < input1.length(); i++)
    {
        for(int j = 0; j < input2.length(); j++)
        {
            saved[i][j] = -1;
        }
    }
    cout << LCS(input1, input2, saved);
    return 0;
}