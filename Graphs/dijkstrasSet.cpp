#include<iostream>
#include<vector>
#include<set>
using namespace std;

// O(E log v)
vector<int> dijkstra(vector<vector<int>> adj[], int n, int s){
    set<pair<int, int>> st;
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;
    st.insert({0, s});
    while(!st.empty()){
        // distance between curr node and source node 
        auto it = *(st.begin());
        int node = it.second;
        int distance = it.first;
        st.erase(it);
        for(auto nei: adj[node]){
            // distance between nei node and curr node 
            int edgeWeight = nei[1];
            // nei node
            int adjNode = nei[0];
            if(distance + edgeWeight < dist[adjNode]){
                if(dist[adjNode] != INT_MAX){
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = distance + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}