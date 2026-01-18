#include<iostream>
#include<vector>
using namespace std;

bool dfs(int start, int c, vector<vector<int>>& graph, vector<int> &color){
    color[start] = c;
    for(auto it: graph[start]){
        if(color[it] == -1){
            if(!dfs(it, !c, graph, color)){
                return false;
            }
        }
        else if(color[it] == c){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> color(n, -1);
    for(int i = 0; i < n; i++){
        if(color[i] == -1 && !dfs(i, 0, graph, color)){
            return false;
        }
    }
    return true;
}