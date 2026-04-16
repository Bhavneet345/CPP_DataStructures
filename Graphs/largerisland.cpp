#include<iostream>
#include<vector>
#include<set>
#include "disjointSets.h"
using namespace std;

bool isValid(int n, int row, int col){
    if(row >= 0 && col >= 0 && row < n && col < n){
        return true;
    }
    return false;
}

int largestIsland(vector<vector<int>>& grid){
    int n = grid.size();
    DisjointSet ds(n * n);
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // merge existing 1's into disjointSet 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 0) continue;
            for(auto direction: directions){
                int newRow = i + direction.first;
                int newCol = j + direction.second;
                if(isValid(n, newRow, newCol) && grid[newRow][newCol] == 1){
                    int nodeNo = i * n + j;
                    int adjnodeNo = newRow * n + newCol;
                    // don't check ultimate parent because if same it'd be returned by first line in defined class
                    ds.unionBySize(nodeNo, adjnodeNo);
                }
            }
        }
    }

    // now deal with all the zero's and try to find the maximum possible island
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1) continue;
            set<int> s;
            for(auto direction: directions){
                int newRow = i + direction.first;
                int newCol = j + direction.second;
                if(isValid(n, newRow, newCol) && grid[newRow][newCol] == 1){
                    int adjnodeNo = newRow * n + newCol;
                    s.insert(ds.findUltimateParent(adjnodeNo));
                }
            }
            int temp = 0;
            for(auto parent: s){
                temp += ds.size[parent];
            }
            ans = max(ans, temp + 1);
        }
    }
    // check max size with all the cells to confirm max size of island
    for(int i = 0; i < n * n; i++){
        ans = max(ans, ds.size[ds.findUltimateParent(i)]);
    }
    return ans;
}