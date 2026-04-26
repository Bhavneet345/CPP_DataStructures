#include<iostream>
#include<vector>
using namespace std;

void dfs(int sr, int sc, vector<vector<int>>& image, vector<vector<int>> &copy, int color, vector<vector<int>> &visited){
    int n = image.size();
    int m = image[0].size();
    visited[sr][sc] = 1;
    copy[sr][sc] = color;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(auto direction: directions){
        int row = direction.first + sr;
        int col = direction.second + sc;
        if(row >= 0 && row < n && col >= 0 && col < m && image[row][col] == image[sr][sc] && !visited[row][col]){
            dfs(row, col, image, copy, color, visited);
        }
    }
    return;
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> copy(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++){
        copy[i] = image[i];
    }
    vector<vector<int>> visited(n, vector<int>(m, 0));
    dfs(sr, sc, image, copy, color, visited);
    return copy;
}