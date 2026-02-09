#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &res){
    vis[node] = 1;
    res.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, res);
        }
    }
    return;
}

// SC -> O(N)
// TC -> O(N) + O(2E)

vector<int> dfsOfGraph(int n, vector<int> adj[]){
    vector<int> vis(n, 0);
    int start = 0;
    vector<int> res;
    dfs(start, adj, vis, res);
    return res;
}