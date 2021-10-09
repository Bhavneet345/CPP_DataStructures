#include<iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
    int temp;
    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[100], len;
    cin>>len;
    cout<<"Enter the elements\n";
    for(int i = 0; i < len; i++)
    {
        cin>>arr[i];
    }
    bubble_sort(arr, len);
    cout<<"Sorted array\n";
    for(int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}