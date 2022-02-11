#include<iostream>
#include<vector>
using namespace std;

bool helper(vector<vector<char>> &board, vector<vector<bool> > &visited, int i, int j, int n, int m, char element)
{
    if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] != element)
    {
        return false;
    }
    if(visited[i][j])
    {
        return true;
    }
    visited[i][j] = true;
    board[i][j] = '.';
    bool result = helper(board, visited, i - 1, j, n, m, element);
    if(!result){
        result = helper(board, visited, i + 1, j, n, m, element);
    }
    if(!result){
        result = helper(board, visited, i, j - 1, n, m, element);
    }
    if(!result){
        result = helper(board, visited, i, j + 1, n, m, element);
    }
    board[i][j] = element;
    return result;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{
    vector<vector<bool> >visisted(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visisted[i][j] && helper(board, visisted, i, j, n, m, board[i][j])){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}