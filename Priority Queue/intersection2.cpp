#include<iostream>
#include<unordered_map>
using namespace std;

void printIntersection(int *arr1, int *arr2, int n, int m)
{
    unordered_map<int, int>map;
    for(int i = 0; i < n; i++)
    {
        map[arr1[i]] += 1;
    }
    for(int i = 0; i < m; i++)
    {
        if(map.find(arr2[i]) != map.end())
        {
            cout << arr2[i] << endl;
            if(map[arr2[i]] > 1)
            {
                map[arr2[i]] -= 1;
            }
            else
            {
                map.erase(arr2[i]);
            }
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