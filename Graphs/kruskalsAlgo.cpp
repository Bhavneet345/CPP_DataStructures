#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class edgeInfo
{
    public:
    int weigth;
    int sv;
    int ev;
};

bool comparator(edgeInfo e1, edgeInfo e2)
{
    return (e1.weigth < e2.weigth);
}

int returnParent(int *parent, int vertex)
{
    if(parent[vertex] == vertex)
    {
        return vertex;
    }
    return returnParent(parent, parent[vertex]);
}

void kruskals(vector<edgeInfo> edges, int n)
{
    int *parent = new int[n];
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    vector<edgeInfo> output;
    sort(edges.begin(), edges.end(), comparator);
    int i = 0;
    int count = 0;
    while(count < n - 1)
    {
        edgeInfo e = edges[i];
        int p1 = returnParent(parent, e.sv);
        int p2 = returnParent(parent, e.ev);
        if(p1 != p2)
        {
            output.push_back(e);
            ++count;
            parent[p1] = p2;
        }
        ++i;
    }
    for(int i = 0; i < output.size(); i++)
    {
        int sv = output[i].sv;
        int ev = output[i].ev;
        int weight = output[i].weigth;
        if(sv < ev)
            cout << sv << " " << ev << " " << weight << endl;
        else
            cout << ev << " " << sv << " " << weight << endl;
    }
    return;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<edgeInfo> edges;
    for(int i = 0; i < e; i++)
    {
        int sv, ev, w;
        cin >> sv >> ev >> w;
        edgeInfo e;
        e.sv = sv;
        e.ev = ev;
        e.weigth = w;
        edges.push_back(e);
    }
    kruskals(edges, n);
    return 0;
}