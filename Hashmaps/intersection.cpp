#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

void printIntersection(int *arr1, int *arr2, int n, int m)
{
    unordered_map<int, int>map1, map2, map3;
    sort(arr1, arr1 + n);
    for(int i = 0; i < n; i++)
    {
        map1[arr1[i]] += 1;
    }
    for(int i = 0; i < m; i++)
    {
        map2[arr2[i]] += 1;
    }
    for(int i = 0; i < n; i++)
    {
        if(map1.count(arr1[i]) > 0 && map2.count(arr1[i]) > 0  && map3.count(arr1[i]) != 1)
        {
            map3[arr1[i]] = min(map1[arr1[i]], map2[arr1[i]]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(map3.count(arr1[i]) > 0)
        {
            for(int i = 0; i < map3[arr1[i]]; i++)
            {
                cout << arr1[i] << endl;
            }
            map3.erase(arr1[i]);
        }
    }
    return;
}

int main()
{
    int n, *input1, m, *input2;
    cin >> n;
    input1 = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> input1[i];
    }
    cin >> m;
    input2 = new int[m];
    for(int i = 0; i < m; i++)
    {
        cin >> input2[i];
    }
    cout << endl;
    printIntersection(input1, input2, n, m);
    return 0;
}