#include<iostream>
#include<vector>
#include<set>
using namespace std;

void dfs(int srow, int scol, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> &vec, 
int row0, int col0){
    int m = grid.size();
    int n = grid[0].size();
    visited[srow][scol] = 1;
    vec.push_back({srow - row0, scol - col0});
    vector<pair<int, int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    for(auto direction: directions){
        int newRow = direction.first + srow;
        int newCol = direction.second + scol;
        if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n 
        && grid[newRow][newCol] == 1 && !visited[newRow][newCol]){
            dfs(newRow, newCol, grid, visited, vec, row0, col0);
        }
    }
    return;
}

int countDisitinctIslands(vector<vector<int>> &grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    set<vector<pair<int, int>>> res;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1 && !visited[i][j]){
                vector<pair<int, int>> vec;
                dfs(i, j, grid, visited, vec, i, j);
                res.insert(vec);
            }
        }
    }
    int ans = res.size();
    return ans;
}