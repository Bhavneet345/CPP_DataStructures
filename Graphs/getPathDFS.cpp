#include<iostream>
#include<vector>
using namespace std;

vector<int>* getPathDFS(int **edges, int n, bool *visited, int sv, int ev)
{
    visited[sv] = true;   
    if(sv == ev)
    {
        vector<int> *res = new vector<int>;
        res->push_back(sv);
        return res;
    }
    for(int i = 0; i < n; i++)
    {
        if(sv == i)
        {
            continue;
        }
        if(edges[sv][i] == 1 && visited[i] == false)
        {
            vector<int> *res = new vector<int>;
            res = getPathDFS(edges, n, visited, i, ev);
            if(res != nullptr)
            {
                res->push_back(sv); 
                return res;  
            }
            delete res;
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
    vector<int> *res = getPathDFS(edges, n, visited, sv, ev);
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