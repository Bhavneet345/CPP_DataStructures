#include<iostream>
using namespace std;

bool hasPathHelper(int **edges, int n, int sv, int ev, bool *visited)
{
    visited[sv] = true;
    if(edges[sv][ev] == 1)
    {
        return true;
    }
    for(int i = 0; i < n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        if(edges[sv][i] == 1 && visited[i] != true)
        {
            if(hasPathHelper(edges, n, i, ev, visited))
            {
                return true;
            }
        }
    }
    return false;
}

bool hasPath(int **edges, int n, int sv, int ev)
{
    if(sv >= n || ev >= n || n == 0)
    {
        return false;
    }
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    bool ans = hasPathHelper(edges, n, sv, ev, visited);
    delete [] visited;
    return ans;
}

int main()
{
    int n, e;
    cin >> n >> e;
    if(n == 0 || e == 0)
    {
        for(int i = 0; i < n; i++)
        {
            cout << i << " ";
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
    int sv, ev;
    cin >> sv >> ev;
    if(hasPath(edges, n, sv, ev))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}