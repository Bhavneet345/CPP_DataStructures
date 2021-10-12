#include<iostream>
using namespace std;

void shiftZeros(int arr[], int len)
{
    int pos = 0, arr_new[100], count  = 0;
    for(int i = 0; i < len; i++)
    {
        if(arr[i] != 0)
        {
            arr_new[pos] = arr[i];
            ++pos;
        }

        else
        {
            ++count;
        }
    }

    for(int i = 0; i < pos; i++)
    {
        arr[i] = arr_new[i];
    }

    for(int i = pos; i < len; i++)
    {
        arr[i] = 0;
    }

    cout<<"Resulting array is\n";
    for(int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    return;
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
    shiftZeros(arr, len);
    return 0;
}