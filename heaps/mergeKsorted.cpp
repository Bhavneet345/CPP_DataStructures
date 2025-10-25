#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input)
{
    vector<int> res;
    priority_queue<int, vector<int>, greater<int> > minheap;
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input[i] -> size(); j++)
        {
            minheap.push(input[i] -> at(j));
        }
    }
    while(!minheap.empty())
    {
        res.push_back(minheap.top());
        minheap.pop();
    }
    return res;
}

int main()
{
    vector<vector<int> *>input;
    int n, elements, data;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> elements;
        vector<int> *temp = new vector<int>;
        for(int i = 0; i < elements; i++)
        {
            cin >> data;
            temp -> push_back(data);
        }
        input.push_back(temp);
    }
    vector<int> res = mergeKSortedArrays(input);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}