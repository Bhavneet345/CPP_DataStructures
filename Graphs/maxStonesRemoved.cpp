#include<iostream>
#include<vector>
#include "disjointSets.h"

// intution of max stones removed = number of stones - number of components

int removeStones(vector<vector<int>>& stones){
    int n = stones.size();
    int maxRow = 0, maxCol = 0;
    for(auto it: stones){
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> map;
    for(auto it: stones){
        int rowNode = it[0];
        int colNode = it[1] + maxRow + 1;
        // making a component of similar rowNo, colNo
        ds.unionBySize(rowNode, colNode);
        // storigng the rowNo/colNo to later find the number of components
        map[rowNode] = 1;
        map[colNode] = 1;
    }
    int cnt = 0;
    for(auto it: map){
        if(ds.findUltimateParent(it.first) == it.first){
            cnt++;
        }
    }
    return abs(cnt - n);
}