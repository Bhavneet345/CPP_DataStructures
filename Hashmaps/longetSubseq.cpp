#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int input[], int size) 
{
    unordered_map<int, bool>map;
    unordered_map<int, int>previndex;
    int start, end;
    for(int i = 0; i < size; i++)
    {
        map[input[i]] = true;
        previndex[input[i]] = i;
    }
    int count = 0, globalseqlength = 1, globalminstart = 0;
    for(int i = 0; i < size; i++)
    {
        count = 0;
        int element = input[i], start = previndex[input[i]];
        while(map[element] != false && map.find(element) != map.end())
        {
            map[element] = false;
            ++element;
            ++count;
        }
        element = input[i] - 1;
        while(map[element] != false && map.find(element) != map.end())
        {
            map[element] = false;
            start = previndex[element];
            ++count;
            --element;
        }
        if(count > globalseqlength)
        {
            globalminstart = start;
            globalseqlength = count;
        }
        else if(count == globalseqlength)
        {
            if(globalminstart > start)
            {
                globalminstart = start;
            }
        }
    }
    vector<int>res;
    res.push_back(input[globalminstart]);
    if(globalseqlength == 1)
    {
        return res;
    }
    res.push_back(input[globalminstart] + globalseqlength - 1);
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