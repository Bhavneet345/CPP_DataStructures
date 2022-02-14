#include<iostream>
#include<vector>
using namespace std;

int findMinVertex(vector<int> cost, vector<bool> visited, int n)
{
    int minVertex = -1;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && (minVertex == -1 || cost[minVertex] > cost[i]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void Dijkstras(int **edges, int n)
{
    vector<int> cost(n, INT_MAX);
    vector<bool> visited(n, false);
    cost[0] = 0;
    for(int i = 0; i < n; i++)
    {
        int minvertex = findMinVertex(cost, visited, n);
        if(minvertex == -1)
        {
            break;
        }
        visited[minvertex] = true;
        for(int j = 0; j < n; j++)
        {
            if(edges[minvertex][j] != 0 && !visited[j])
            {
                int sum = cost[minvertex] + edges[minvertex][j];
                if(sum < cost[j])
                {
                    cost[j] = sum; 
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << i << " " << cost[i] << endl;
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
    Dijkstras(edges, n);
    return 0;
}

