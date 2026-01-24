#include<iostream>
#include<vector>
using namespace std;

bool dfs(int start, const vector<vector<int>>& adj, vector<int> &visited, vector<int> &pthVisited){
    visited[start] = 1;
    pthVisited[start] = 1;
    for(auto nei: adj[start]){
        if(!visited[nei]){
            if(dfs(nei, adj, visited, pthVisited)){
                return true;
            }
        }
        else if(pthVisited[nei]){
            return true;
        }
    }
    pthVisited[start] = 0;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    for (const auto& pre : prerequisites) {
        adj[pre[0]].push_back(pre[1]);
    }
    vector<int> visited(numCourses, 0);
    vector<int> pthVisited(numCourses, 0);
    for(int i = 0; i < numCourses; ++i){
        if(!visited[i]){
            if(dfs(i, adj, visited, pthVisited)) return false;
        }
    }
    return true;
}