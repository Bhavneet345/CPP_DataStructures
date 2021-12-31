#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<string> generateBinaryNumbers(int n)
{
    vector<string>result;
    queue<string>pending;
    pending.push("1");
    for(int i = 0; i < n; i++)
    {
        string binary = pending.front();
        pending.pop();
        result.push_back(binary);
        pending.push(binary + "0");
        pending.push(binary + "1");
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<string> res = generateBinaryNumbers(n);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}