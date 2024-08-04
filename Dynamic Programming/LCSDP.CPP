#include<iostream>
using namespace std;

int LCS(string input1, string input2)
{
    int m = input1.length(), n = input2.length();
    int **output = new int*[m + 1];
    for(int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }

    //filling the first row
    for(int i = 0; i <= n; i++)
    {
        output[0][i] = 0;
    }

    //filling the column
    for(int i = 0; i <= m; i++)
    {
        output[i][0] = 0;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(input1[m - i] == input2[n - j])
            {
                output[i][j] = output[i - 1][j - 1] + 1;
            }
            else
            {
                int res1 = output[i - 1][j];
                int res2 = output[i][j - 1];
                int res3 = output[i - 1][j - 1];
                output[i][j] = max(res1, max(res2, res3));
            }
        }
    }
    return output[m][n];
}

int main()
{
    string input1, input2;
    cin >> input1 >> input2;
    cout << LCS(input1, input2);
    return 0;
}