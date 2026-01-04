// only work with directed graph, but whenever not given just make two sided direction and works with -ve weights
// relax eaxh edge for v-1 times
#include<iostream>
#include<vector>
using namespace std;

vector<int> bellman_ford(int v, vector<vector<int>> &edges, int s){
    vector<int> dist(v, INT_MAX);
    dist[s] = 0;
    // O(VE)
    for(int i = 0; i < v; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            // n - 1 relaxation of edges
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    // nth relaxation to check negative cycle
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    return dist;
}