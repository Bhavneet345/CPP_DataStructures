#include<iostream>
using namespace std;

int twoStacks(int arr1[], int n, int arr2[], int m, int maxSum)
{
    int x = 0, y = 0, sum = 0, ans = 0;
    while(x < n && sum + arr1[x] <= maxSum)
    {
        sum += arr1[x++];
    }
    ans = x;
    while(y < m)
    {
        sum += arr2[y++];
        while(sum > maxSum && x >= 0)
        {
            sum -= arr1[--x];
        }
        if(sum <= maxSum && x + y > ans)
        {
            ans = x + y;
        }
    }
    return ans;
}

int main()
{
    int n, m, maxSum;
    cin >> n >> m >> maxSum;
    int *arr1 = new int[n], *arr2 = new int[m];
    for(int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    cout << twoStacks(arr1, n, arr2, m, maxSum);
    return 0;
}
