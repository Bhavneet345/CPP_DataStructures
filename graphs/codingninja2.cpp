#include<iostream>
#include<vector>
using namespace std;

int isValid(int x, int y, int n, int m)
{
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool helper(vector<vector<char> > &board, int x, int y, int m, int n, string input, vector<vector <bool> > &visited)
{
    if(input.length() == 1)
    {
        return true;
    }
    visited[x][y] = true;
    int dxdy[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
    for(int i = 0; i < 8; i++)
    {
        int newx = x + dxdy[i][0];
        int newy = y + dxdy[i][1];
        if(isValid(newx, newy, n, m) && board[newx][newy] == input[1] && !visited[newx][newy])
        {
            bool ans = helper(board, newx, newy, n, m, input.substr(1), visited);   
            if(ans){
                return ans;
            }
               
        }
    }
    visited[x][y] = false;
    return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    vector<vector<bool> >visited(m, vector<bool>(n, false));
    string s = "CODINGNINJA";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==s[0]){
                bool ans=helper(board,i, j, n, n ,s, visited);
                if(ans)
                    return ans;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char> > board(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << (hasPath(board, n, m) ? 1 : 0);
    return 0;
}
