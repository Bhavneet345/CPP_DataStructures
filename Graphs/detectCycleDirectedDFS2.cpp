#include<iostream>
#include<vector>
using namespace std;

// T.C - O(V + E) and S.C - O(N)
bool dfs(int start, vector<int> adj[], vector<int> &visited){
    visited[start] = 2;
    for(auto it: adj[start]){
        if(!visited[it]){
            if(dfs(it, adj, visited)){
                return true;
            }
        }
        else if(visited[it] == 2){
            return true;
        }
    }
    visited[start] = 1;
    return false;
}

bool isCycle(vector<int> adj[]){
    int n = adj->size();
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[i] && dfs(i, adj, visited)){
            return true;
        }
    }
    return false;
}