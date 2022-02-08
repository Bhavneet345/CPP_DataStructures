#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int>* getPathBFS(int **edges, int n, int sv, int ev)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    if(sv == ev)
    {
        vector<int> *res = new vector<int>;
        res->push_back(sv);
        return res;
    }
    queue<int> pendingVertices;
    unordered_map<int, int> contributingVertex;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty())
    {
        int current = pendingVertices.front();
        pendingVertices.pop();
        if(current == ev)
        {
            vector<int> *res = new vector<int>;
            res->push_back(current);
            int vertex = contributingVertex[current];
            while(vertex != sv)
            {
                res -> push_back(vertex);
                vertex = contributingVertex[vertex];
            }
            res -> push_back(vertex);
            return res;
        }
        for(int i = 0; i < n; i++)
        {
            if(i == current)
            {
                continue;
            }
            if(edges[current][i] == 1 && visited[i] == false)
            {
                visited[i] = true;
                contributingVertex[i] = current;
                pendingVertices.push(i);
            }
        }
    }
    return nullptr;
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
    int sv, ev;
    cin >> sv >> ev;
    vector<int> *res = getPathBFS(edges, n, sv, ev);
    if(res == nullptr)
    {
        return 0;
    }
    for(int i = 0; i < res -> size(); i++)
    {
        cout << res -> at(i) << " ";
    }
    return 0;
}