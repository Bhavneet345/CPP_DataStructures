#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void returnConnectedHelper(int **edges, int n, int sv, bool *visited, vector<int> &res)
{
    visited[sv] = true;
    res.push_back(sv);
    for(int i = 0; i < n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        else if(edges[sv][i] == 1 && visited[i] == false)
        {
            returnConnectedHelper(edges, n, i, visited, res);
        }
    }
    return;
}

void returnAllConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<int> res;
    returnConnectedHelper(edges, n, 0, visited, res);
    while(!res.empty())
    {
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        res.erase(res.begin(), res.end());
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                returnConnectedHelper(edges, n, i, visited, res);
            }
        }
        cout << endl;
    }
    return;
}

int main()
{
    int n, e;
    cin >> n >> e;
    if(n == 0 || e == 0)
    {
        for(int i = 0; i < n; i++)
        {
            cout << i << endl;
        }
        return 0;
    }
    int **edges = new int*[n];
    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++)
    {
        int fv, sv;
        cin >> fv >> sv;
        edges[fv][sv] = 1;
        edges[sv][fv] = 1;
    }
    returnAllConnected(edges, n);
    return 0;
}