#include<iostream>
using namespace std;

int find3Cycles(int **edges, int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(edges[i][j] == 1)
            {
                for(int k = j + 1; k < n; k++)
                {
                    if(edges[j][k] == 1 && edges[i][k] == 1)
                    {
                        ++count;
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    int n, e;
    cin >> n >> e;
    if(n == 0 || e == 0)
    {
        return 0;
    }
    int **edges = new int*[n];
    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++)
    {
        int fv, sv;
        cin >> fv >> sv;
        edges[fv][sv] = 1;
        edges[sv][fv] = 1;
    }
    cout << find3Cycles(edges, n);
    return 0;
}