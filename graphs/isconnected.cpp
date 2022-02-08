#include<iostream>
using namespace std;

void isConnectedhelper(int **edges, int n, int sv, bool *visited)
{
    visited[sv] = true;
    for(int i = 0; i < n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        if(edges[sv][i] == 1 && visited[i] == false)
        {
            isConnectedhelper(edges, n, i, visited);
        }
    }
    return;
}

bool isConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    isConnectedhelper(edges, n, 0, visited);
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            delete [] visited;
            return false;
        }
    }
    delete [] visited;
    return true;
}

int main()
{
    int n, e;
    cin >> n >> e;
    if(n == 0 || e == 0)
    {
       if(n == 0)
       {
           cout << "true";
       }
       else if(e == 0 && n == 1)
       {
           cout << "true";
       }
       else 
       {
           cout << "false";
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
    int ans = isConnected(edges, n);
    if(ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}