#include<iostream>
using namespace std;

int sum(int *arr, int size)
{
    if(size == 1)
    {
        return arr[0];
    }
    int ans = arr[0] + sum(arr + 1, size - 1);
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the sze of the array\n";
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = sum(arr, n);
    delete [] arr;
    cout<<"The sum is "<<ans;
    return 0;
}