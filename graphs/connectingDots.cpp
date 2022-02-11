#include<iostream>
#include<vector>
using namespace std;

bool helper(vector<vector<char> > &board, vector<vector<bool> > &visited, int i, int j, int n, int m, int startx, int starty, char element)
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
    int dxdy[][4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int k = 0; k < 4; k++)
    {
        int newx = i + dxdy[k][0];
        int newy = j + dxdy[k][1];
        if(newx == startx && newy == starty)
        {
            continue;
        }
        bool res = helper(board, visited, newx, newy, n, m, i, j, element);
        if(res == true)
        {
            return res;
        }
    }
    return false;
}

bool hasCycle(vector<vector<char> > &board, int n, int m)
{
    vector<vector<bool> >visisted(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visisted[i][j] && helper(board, visisted, i, j, n, m, i, j, board[i][j])){
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char> > board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}
