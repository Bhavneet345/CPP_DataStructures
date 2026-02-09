#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detect(int src, vector<int> adj[], vector<int> &visited){
    visited[src] = 1;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto it: adj[curr]){
            if(!visited[it]){
                q.push(it);
            }
            else if(it != curr){
                return false;
            }
        }
    }
    return true;
}

bool isCycle(int n, vector<int> adj[]){
    bool cycle = false;
    vector<int> visited(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            cycle =  detect(i, adj, visited);
            if(cycle){
                return true;
            }
        }
    }
    return false;
}