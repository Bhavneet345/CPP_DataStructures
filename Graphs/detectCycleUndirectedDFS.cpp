#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// time - O(N + 2E) + O(N)
bool detect(int src, int parent, vector<int> adj[], vector<int> &visited){
    visited[src] = true;
    for(auto nei: adj[src]){
        if(!visited[nei]){
            if(detect(nei, src, adj, visited)){
                return true;
            }
        }
        else if(nei != parent){
            return true;
        }
    }
    return false;
}

bool isCycle(int n, vector<int> adj[]){
    bool cycle = false;
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            cycle =  detect(i, -1, adj, visited);
            if(cycle){
                return true;
            }
        }
    }
    return false;
}