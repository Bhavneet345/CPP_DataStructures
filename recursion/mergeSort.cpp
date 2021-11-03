#include<iostream>
using namespace std;
 
void merge2sorted(int arr[], int start, int end, int mid)
{
    int i = start, j = mid + 1, k = 0, brr[end - start + 1];
    while (i <= mid && j <= end)
    {
        if(arr[i] < arr[j])
        {
            brr[k] = arr[i];
            i++;
        }
        else
        {
            brr[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        brr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        brr[k] = arr[j];
        j++;
        k++;
    }
    for(int i = start, j = 0; i <= end; i++, j++)
    {
        arr[i] = brr[j];
    }
}

void helper(int arr[], int start, int end)
{
    if(start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    helper(arr, start, mid);
    helper(arr, mid + 1, end);
    merge2sorted(arr, start, end, mid);
}

void mergesort(int arr[], int size)
{
    helper(arr, 0, size - 1);   
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
    mergesort(arr,n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}