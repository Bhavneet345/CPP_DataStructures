#include<iostream>
#include<vector>
using namespace std;

int findminimum(vector<int> weight, vector<bool> visited, int n)
{
    int minimum = -1;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && (minimum == -1 || weight[minimum] > weight[i]))
        {
            minimum = i;
        }
    }
    return minimum;
}

void Djikstra(int **edges, int n)
{
    vector<bool> visited(n, false);
    vector<int> weights(n, INT_MAX);
    weights[0] = 0;
    for(int i = 0; i < n; i++)
    {
        int minimumvertex = findminimum(weights, visited, n);
        if(minimumvertex == -1)
        {
            break;   
        }
        visited[minimumvertex] = true;
        for(int j = 0; j < n; j++)
        {
            if(edges[minimumvertex][j] != 0 && !visited[j])
            {
                int sum = weights[minimumvertex] + edges[minimumvertex][j];
                if(sum < weights[j])
                {
                    weights[j] = sum;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << i << " " << weights[i] << endl;
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
        int sv, ev, weight;
        cin >> sv >> ev >> weight;
        edges[sv][ev] = weight;
        edges[ev][sv] = weight;
    }
    Djikstra(edges, n);
    return 0;
}