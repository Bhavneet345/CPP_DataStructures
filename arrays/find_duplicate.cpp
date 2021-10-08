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

int duplicate(int arr[], int n)
{
    int unique = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == arr[i + 1])
        {
            unique = arr[i];
            return unique;
        }
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
    bubble_sort(arr, n);
    int duplicate_element = duplicate(arr, n);
    cout<<"duplicate element is "<<duplicate_element;
    return 0;
}