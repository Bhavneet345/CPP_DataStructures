#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> removeDuplicates(int *input, int size)
{
    unordered_map<int, bool> map;
    vector<int> res;
    for(int i = 0; i < size; i++)
    {
        if(map.count(input[i]) > 0)
        {
            continue;
        }
        map[input[i]] = true;
        res.push_back(input[i]);
    }
    return res;
}

int main()
{
    int n, *input;
    cin >> n;
    input = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    vector<int> res = removeDuplicates(input, n);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}