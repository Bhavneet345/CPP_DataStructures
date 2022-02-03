#include<iostream>
using namespace std;

int lootHouses(int *arr, int n)
{ 
    int *saved = new int[n + 1];
    saved[n] = 0;
    saved[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        int including = saved[i + 2] + arr[i];
        int excluding = saved[i + 1];
        saved[i] = max(including, excluding);
    }
    return max(saved[0], saved[1]);
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

