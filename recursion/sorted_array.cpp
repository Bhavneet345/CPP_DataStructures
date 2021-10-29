#include<iostream>
using namespace std;

bool is_sorted(int arr[], int size)
{
    if(size == 1 || size == 0)
    {
        return true;
    }

    if(arr[0] > arr[1])
    {
        return false;
    }

    bool sorted = is_sorted(arr + 1, size - 1);
    return sorted;
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    if(is_sorted(arr, n))
    {
        cout<<"True";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}