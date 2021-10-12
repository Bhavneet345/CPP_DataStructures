#include<iostream>
using namespace std;

void reverse(int arr[], int len)
{
    int i = 0, j = len - 1;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void rotate(int arr[], int len, int shift)
{
    int temp[100];
    for(int i = 0; i < shift; i++)
    {
        temp[i] = arr[i];
    }

    reverse(arr, len);
    reverse(arr, len - shift);

    int start = len - shift, k = 0;
    for(int i = start; i < len; i++)
    {
        arr[i] = temp[k];
        k++;
    }

    for(int j = 0; j < len ; j++)
    {
        cout<<arr[j]<<" ";
    }
}

int main()
{
    int arr[100], len, shift;
    cin>>len;
    cout<<"Enter the elements\n";
    for(int i = 0; i < len; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the shifting parameter\n";
    cin>>shift;
    rotate(arr, len, shift);
    return 0;
}