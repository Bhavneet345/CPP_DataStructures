#include<iostream>
using namespace std;

void swap_alternate(int arr[], int n)
{
    for(int i = 0; i < n - 1; i += 2)
    {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}

int main()
{
    int arr[100], n;
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"New array is \n";
    swap_alternate(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}