#include<iostream>
#include<vector>
using namespace std;

bool helper(vector<vector<char>> &board,int n,int m,int i,int j,bool** visited,string s){
    if(i>=n||i<0||j>=m||j<0)
        return false;
    if(s.size()==0)
        return true;
    if(s[0]!=board[i][j]||visited[i][j])
        return false;
    visited[i][j]=true;
    bool ans=false;
    if(board[i][j]==s[0]){
        if(!ans)
            ans=helper(board,n,m,i+1,j,visited,s.substr(1));
        if(!ans)
            ans=helper(board,n,m,i+1,j+1,visited,s.substr(1));
        if(!ans)
            ans=helper(board,n,m,i+1,j-1,visited,s.substr(1));
        if(!ans)
            ans=helper(board,n,m,i,j+1,visited,s.substr(1));
        if(!ans)
            ans=helper(board,n,m,i,j-1,visited,s.substr(1));
        if(!ans)
            ans=helper(board,n,m,i-1,j,visited,s.substr(1));
        if(!ans)
            ans=helper(board,n,m,i-1,j-1,visited,s.substr(1));
        if(!ans)
            ans=helper(board,n,m,i-1,j+1,visited,s.substr(1));
    }
    visited[i][j]=false;
    return ans;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    bool **visited=new bool*[n];
    for(int i=0;i<n;i++){
        visited[i]=new bool[m];
        for(int j=0;j<m;j++)
            visited[i][j]=false;
    }
    string s="CODINGNINJA";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==s[0]){
                bool ans=helper(board,n,m,i,j,visited,s);
                if(ans)
                    return ans;
            }
        }
    }
    for(int i=0;i<n;i++)
        delete []visited[i];
    delete []visited;
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