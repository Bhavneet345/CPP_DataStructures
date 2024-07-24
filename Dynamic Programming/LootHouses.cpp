#include<iostream>
using namespace std;

int lootHouses(int *arr, int n)
{
    if(n <= 0)
    {
        return 0;
    }
    int including = lootHouses(arr + 2, n - 2) + arr[0];
    int excluding = lootHouses(arr + 1, n - 1);
    int ans = max(including, excluding);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << lootHouses(arr, n);
    return 0;
}