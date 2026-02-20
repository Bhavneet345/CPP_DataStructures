#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i; 
            size[i] = 1;
        }
    }
    int findUltimateParent(int node){
        if(parent[node] == node){
            return node;
        }
        // path compression 
        return parent[node] = findUltimateParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ultParent_u = findUltimateParent(u);
        int ultParent_v = findUltimateParent(v);
        if(ultParent_u == ultParent_v){
            return;
        }
        if(rank[ultParent_u] > rank[ultParent_v]){
            parent[ultParent_v] = ultParent_u;
        }
        else if(rank[ultParent_u] < rank[ultParent_v]){
            parent[ultParent_u] = ultParent_v;
        }
        // if same rank then change ultimate parent of v's ultparent to ultimate parent of u
        else{
            parent[ultParent_v] = ultParent_u;
            rank[ultParent_u]++;
        }
        return;
    }
    void unionBySize(int u, int v){
        int ultParent_u = findUltimateParent(u);
        int ultParent_v = findUltimateParent(v);
        if(ultParent_u == ultParent_v){
            return;
        }
        if(size[ultParent_u] > size[ultParent_v]){
            parent[ultParent_v] = ultParent_u;
            size[ultParent_u] = size[ultParent_u] + size[ultParent_v];
        }
        else if(size[ultParent_u] < size[ultParent_v]){
            parent[ultParent_u] = ultParent_v;
            size[ultParent_v] = size[ultParent_v] + size[ultParent_u];
        }
        // if same size then change ultimate parent of v's ultparent to ultimate parent of u
        else{
            parent[ultParent_v] = ultParent_u;
            size[ultParent_u] = size[ultParent_u] + size[ultParent_v];
        }
        return;
    }
};