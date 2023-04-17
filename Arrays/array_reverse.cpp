#include<iostream>
using namespace std;

void reverse(int arr[], int n)
{
    int i = 0, j = n - 1, temp;

    while(i < j)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    int arr[100];
    int n;
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Reversed array is \n";
    reverse(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}