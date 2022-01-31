#include<iostream>
using namespace std;

int LCS(string input1, string input2)
{
    if(input1.empty() || input2.empty())
    {
        return 0;
    }
    else if(input1[0] == input2[0])
    {
        int ans = LCS(input1.substr(1), input2.substr(1));
        return ans + 1;
    }
    int case1 = LCS(input1.substr(1), input2);
    int case2 = LCS(input1, input2.substr(1));
    int ans = max(case1, case2);
    return ans;
}

int main()
{
    string input1, input2;
    cin >> input1 >> input2;
    cout << LCS(input1, input2);
    return 0;
}