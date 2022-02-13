#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findMinVertex(vector<int> weight, vector<bool> visited, int n)
{
    int minVertex = -1;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **edges, int n)
{
    vector<bool> visited(n, false);
    vector<int> weight(n, INT_MAX);
    vector<int> parent(n);
    weight[0] = 0;
    parent[0] = -1;
    for(int i = 0; i < n; i++)
    {
        int minvertex = findMinVertex(weight,visited,n);
        if(minvertex == -1)
        {
            break;
        }
        visited[minvertex] = true;
        for(int j = 0; j < n; j++)
        {
            if(edges[minvertex][j] != 0 && !visited[j] && edges[minvertex][j] < weight[j])
            {
                weight[j] = edges[minvertex][j];
                parent[j] = minvertex;
            }
        }
    }
    for(int i = 1; i < n; i++)
    {
        if(parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << endl;
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << endl;
        }
    }
    return;
}

int main()
{
    int n, e;
    cin >> n >> e;
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
        int sv, ev, w;
        cin >> sv >> ev >> w;
        edges[sv][ev] = w;
        edges[ev][sv] = w;
    }
    prims(edges, n);
    return 0;
}