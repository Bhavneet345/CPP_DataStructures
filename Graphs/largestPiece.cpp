#include<iostream>
#include<vector>
using namespace std;

int helper(vector<vector<int> > &cake, int n, int i, int j, bool **visited)
{
    if(cake[i][j] != 1)
    {
        return 0;
    }
    visited[i][j] = true;
    int ans = 1;
    if(i > 0 && !visited[i - 1][j])
       ans += helper(cake, n, i - 1, j, visited);
    if(i < n - 1 && !visited[i + 1][j])
       ans += helper(cake, n, i + 1, j, visited);
    if(j < n -1 && !visited[i][j + 1])   
       ans += helper(cake, n, i, j + 1, visited);
    if(j > 0 && !visited[i][j - 1])
       ans += helper(cake, n, i, j - 1, visited);
    return ans;
}

int getBiggestPieceSize(vector<vector<int> > &cake, int n)
{
    bool **visited = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for(int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    int maximum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(cake[i][j] == 1 && !visited[i][j])
            {
                int ans = helper(cake, n, i, j, visited);
                if(ans > maximum)
                {
                    maximum = ans;
                }
            }
        }
    }
    return maximum;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int> > cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
    return 0;
}