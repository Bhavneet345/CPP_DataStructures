// multi-source shortest path algorithm and also helps in detecting -ve cycle
#include<iostream>
#include<vector>
using namespace std;

void shortest_distance(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = INT_MAX;
            }
            if(i == j){
                matrix[i][j] = 0;
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // -ve cycle 
    for(int i = 0; i < n; i++){
        if(matrix[i][i] < 0){
            return;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == INT_MAX){
                matrix[i][j] = -1;
            }
        }
    }

    return;
}