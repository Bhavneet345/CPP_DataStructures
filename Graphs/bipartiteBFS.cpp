#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool isBipartiteHelper(int start, vector<vector<int>>& graph, vector<int> color){
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while(!q.empty()){
        int curr = q.front();
        int currColor = color[curr];
        q.pop();
        for(auto it: graph[curr]){
            if(color[it] == -1){
                color[it] = !currColor;
                q.push(it);
            }
            else if(color[it] == currColor){
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph){
    int n = graph.size();
    vector<int> color(n, -1);
    for(int i = 0; i < n; i++){
        if(color[i] == -1){
            if(!isBipartiteHelper(i, graph, color)){
                return false;
            }
        }
    }
    return true;
}