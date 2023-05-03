#include<iostream>
using namespace std;

void insertionSort(int arr[], int len)
{
    int k;
    for(int i = 1; i < len; i++)
    {
        int temp = arr[i], min_pos = i;
        
        for(int j = i - 1; j >= 0; j--)
        {
            if(arr[i] < arr[j])
            {
                min_pos = j;
            }
        }
        
        for(k = i; k > min_pos; k--)
        {
            arr[k] = arr[k - 1];
        }
        arr[k] = temp;
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
    insertionSort(arr, len);
    cout<<"Sorted array\n";
    for(int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}