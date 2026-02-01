#include<iostream>
#include<vector>
using namespace std;

// T.C - O(V + E) and S.C - O(2N)
bool dfs(int start, vector<int> adj[], vector<int> &visited, vector<int> &pthVisited){
    visited[start] = 1;
    pthVisited[start] = 1;
    for(auto it: adj[start]){
        if(!visited[it]){
            if(dfs(it, adj, visited, pthVisited)){
                return true;
            }
        }
        else if(pthVisited[it]){
            return true;
        }
    }
    pthVisited[start] = 0;
    return false;
}

bool isCycle(vector<int> adj[]){
    int n = adj->size();
    vector<int> visited(n, 0);
    vector<int> pthVisited(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[i] && dfs(i, adj, visited, pthVisited)){
            return true;
        }
    }
    return false;
}