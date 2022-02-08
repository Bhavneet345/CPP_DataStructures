#include<iostream>
#include<queue>
using namespace std;

void BFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        cout << currentVertex << " ";
        pendingVertices.pop();
        for(int i = 0; i < n; i++)
        {
            if(i == currentVertex)
            {
                continue;
            }
            if(edges[currentVertex][i] == 1 && visited[i] != true)
            {
                visited[i] = true;
                pendingVertices.push(i);
            }
        } 
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            BFS(edges, n, i, visited);
        }
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
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    BFS(edges, n, 0, visited);
    delete [] visited;
    return 0;
}