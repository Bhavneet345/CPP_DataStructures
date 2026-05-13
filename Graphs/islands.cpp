#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int row, int col, vector<vector<int> > &visited, vector<vector<char>>& grid){
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (auto [dr, dc] : directions) {
            int nr = row + dr;
            int nc = col + dc;
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1' && visited[nr][nc] == 0) {
                q.push({nr, nc});
                visited[nr][nc] = 1;
            }
        }
    }
    return;
}

int numIslands(vector<vector<char>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int> > visited(m, vector<int>(n, 0));
    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1 && !visited[i][j]){
                bfs(i, j, visited, grid);
                cnt++;
            }
        }
    }
    return cnt;
}