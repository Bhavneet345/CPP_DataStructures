#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *input, int size) 
{
    unordered_map<int, int>map;
    vector<int>res, max;
    int maxsize = 0;
    for(int i = 0; i < size; i++)
    {
        map[input[i]] = i;
    }
    for(int i = 0; i < size; i++)
    {
        int element = input[i];
        if(map.find(element + 1) != map.end())
        {
            while(map.find(element) != map.end())
            {
                max.push_back(element);
                element += 1;
            }
            if(maxsize < max.size())
            {
                res.erase(res.begin(), res.end());
                res.push_back(max[0]);
                res.push_back(max[max.size() - 1]);
                maxsize = max.size();
            }
            max.erase(max.begin(), max.end());
        }
    }
    if(res.size() == 0)
    {
        res.push_back(input[0]);
        return res;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    vector <int> res = longestConsecutiveIncreasingSequence(input, n);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}