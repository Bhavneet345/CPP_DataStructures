#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
    vector<pair<int, int>> adj[n];
    for(auto it: flights){
        adj[it[0]].push_back({it[1], it[2]});
    }
    // first priority of judgement be the stops not the distance
    queue<pair<int, pair<int, int>>> pq;
    // distance, stops, node
    pq.push({0, {0, src}});
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while(!pq.empty()){
        int dis = pq.front().first;
        int stops = pq.front().second.first;
        int node = pq.front().second.second;
        pq.pop();
        if(stops > k){
            continue;
        }
        for(auto nei: adj[node]){
            int adjNode = nei.first;
            int wt = nei.second;
            if(wt + dis < dist[adjNode] && stops <= k){
                dist[adjNode] = wt + dis;
                pq.push({dist[adjNode], {stops + 1, adjNode}});
            }
        }
    }
    if(dist[dst] == INT_MAX){
        return -1;
    }
    return dist[dst];
}