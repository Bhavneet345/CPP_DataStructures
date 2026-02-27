#include<iostream>
#include<vector>
using namespace std;

bool detect(int src, vector<vector<int>>& graph, vector<int> &visited,   vector<int> &pvisited, vector<int> &check){
    visited[src] = 1;
    pvisited[src] = 1;
    check[src] = 0;
    for(auto it: graph[src]){
        if(!visited[it]){
            if(detect(it, graph, visited, pvisited, check)){
                check[src] = 0;
                return true;
            }
        }
        else if(pvisited[it]){
            check[src] = 0;
            return true;
        }
    }
    pvisited[src] = 0;
    check[src] = 1;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> pvisited(n, 0);
    vector<int> check(n, 0);
    vector<int> safenodes;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            detect(i, graph, visited, pvisited, check);
        }
    }
    for(int i = 0; i < n; i++){
        if(check[i]){
            safenodes.push_back(i);
        }
    }
    return safenodes;
}