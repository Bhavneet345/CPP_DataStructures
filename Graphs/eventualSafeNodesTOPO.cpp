#include<iostream>
#include<vector>
using namespace std;

// reverse the graph
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> adj[n];
    for(int i = 0; i < n; i++){
        for(auto it: graph[i]){
            adj[it].push_back(i);
        }
    }
    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++){
        for(auto nei: adj[i]){
            indegree[nei]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> res;
    while(!q.empty()){
        int front = q.front();
        res.push_back(front);
        q.pop();
        for(auto nei: adj[front]){
            indegree[nei]--;
            if(indegree[nei] == 0){
                q.push(nei);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}