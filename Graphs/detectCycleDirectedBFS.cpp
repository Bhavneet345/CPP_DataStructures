// using kahn's algorithm - topological sort

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool topoSort(vector<vector<int>> &adj, int n){
    vector<int> indegree(n , 0);
    queue<int> q;
    for(int i = 0; i < n; i++){
        for(auto it: adj[i]){
            indegree[it] += 1;
        }
    }
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cnt++; 
        for(auto it: adj[curr]){
            indegree[it] -= 1;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    if(cnt != n){
        return true;
    }
    return false;
}