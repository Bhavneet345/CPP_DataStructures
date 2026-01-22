#include<iostream>
#include<vector>
#include "disjointSets.h"
using namespace std;

// using disjointSet because dynamically forming graph 

int makeConnected(int n, vector<vector<int>>& connections){
    DisjointSet ds(n);
    int extra = 0;
    for(auto it: connections){
        int node1 = it[0];
        int node2 = it[1];
        if(ds.findUltimateParent(node1) == ds.findUltimateParent(node2)){
            extra++;
            continue;
        }
        ds.unionBySize(node1, node2);
    }
    int remComp = 0;
    for(int i = 0; i < n; i++){
        if(ds.findUltimateParent(i) == i){
            remComp += 1;
        }
    }
    if(remComp - 1 <= extra){
        return remComp - 1;
    }
    return -1;
}