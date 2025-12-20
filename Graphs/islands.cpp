#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void returnConnectedHelper(int **edges, int n, int sv, bool *visited)
{
    visited[sv] = true;
    for(int i = 0; i < n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        else if(edges[sv][i] == 1 && visited[i] == false)
        {
            returnConnectedHelper(edges, n, i, visited);
        }
    }
    return;
}

int returnAllConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int count = 1;
    returnConnectedHelper(edges, n, 0, visited);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            ++count;
            returnConnectedHelper(edges, n, i, visited);
        }
    }
    return count;
}

int main()
{
    int n, e;
    cin >> n >> e;
    if(n == 0 || e == 0)
    {
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            ++count;
        }
        cout << count;
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
    cout << returnAllConnected(edges, n);
    return 0;
}