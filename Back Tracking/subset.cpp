#include<iostream>
using namespace std;

int countSubset(int *arr, int size, int k)
{
    if(size == 0 || k == 0)
    {
        if(k == 0)
        {
            return 1;
        }
        return 0;
    }
    int count = 0;
    if(k - arr[0] >= 0)
    {
        count += countSubset(arr + 1, size - 1, k - arr[0]);
    }
    count += countSubset(arr + 1, size - 1, k);
    return count;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << countSubset(arr, n, k) << endl;
    }
    return 0;
}