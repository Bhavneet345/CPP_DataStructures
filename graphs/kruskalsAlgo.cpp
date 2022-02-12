#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class edgeInfo
{
    public:
    int weight;
    int sv;
    int ev;
};

bool comparator(edgeInfo e1, edgeInfo e2)
{
    return (e1.weight < e2.weight);
}

int findParent(int vertex, int *parent)
{
    if(parent[vertex] == vertex)
    {
        return vertex;
    }
    return findParent(parent[vertex], parent);
}

void kruskals(edgeInfo *edges, int n, int e)
{
    int *parent = new int[n];
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    vector<edgeInfo> minimumSpanningTree;
    int count = 0, i = 0;
    while(count < n - 1 && i < e)
    {
        edgeInfo e = edges[i];
        int p1 = findParent(e.sv, parent);
        int p2 = findParent(e.ev, parent);
        if(p1 != p2)
        {
            minimumSpanningTree.push_back(e);
            parent[p1] = p2;
            ++count;
        }
        ++i;
    }
    for(int i = 0; i < minimumSpanningTree.size(); i++)
    {
        edgeInfo e = minimumSpanningTree[i];
        if(e.sv <= e.ev)
            cout << e.sv << " " << e.ev << " " << e.weight << endl;
        else
            cout << e.ev << " " << e.sv << " " << e.weight << endl;
    }
    return;
}

int main()
{
    int n, e;
    cin >> n >> e;
    edgeInfo *edges = new edgeInfo[e];
    for(int i = 0; i < e; i++)
    {
        edgeInfo e;
        cin >> e.sv >> e.ev >> e.weight;
        edges[i] = e;
    }
    sort(edges, edges + e, comparator);
    
    kruskals(edges, n, e);
    return 0;
}