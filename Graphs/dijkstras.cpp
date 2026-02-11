#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> dijkstra(vector<vector<int>> adj[], int n, int s){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        // distance between curr node and source node 
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto nei: adj[node]){
            // distance between nei node and curr node 
            int edgeWeight = nei[1];
            // nei node
            int adjNode = nei[0];
            if(distance + edgeWeight < dist[adjNode]){
                dist[adjNode] = distance + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}