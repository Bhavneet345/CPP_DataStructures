#include<iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int count = 0, pos = 0, element = arr[start];
    for(int i = start + 1; i <= end; i++)
    {
        if(element > arr[i])
        {
            count++;
        }
    }
    pos = start + count;
    for(int i = start; i < pos; i++)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
    int i = start, j = end;
    while(i < pos || j > pos)
    {
        if(arr[i] < arr[pos])
        {
            i++;
        }
        else if(arr[j] >= arr[pos])
        {
            j--;
        }
        else
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    return pos;
}

void helper(int arr[], int start, int end)
{
    if(start >= end)
    {
        return;
    }
    int pos = partition(arr, start, end);
    helper(arr, start, pos - 1);
    helper(arr, pos + 1, end);
}

void quickSort(int arr[], int size)
{
    helper(arr, 0, size - 1);
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quickSort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

