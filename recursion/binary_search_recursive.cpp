#include<iostream>
using namespace std;

int binarySerach(int arr[], int element, int start, int end)
{
    int mid = (start + end) / 2;
    if(start <= end)
    {
        if(arr[mid] < element)
        {
            return binarySerach(arr, element, mid + 1, end);
        }
        else if(arr[mid] > element)
        {
            return binarySerach(arr, element, start, mid - 1);
        }
        return mid;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n, element;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cin>>element;
    int pos = binarySerach(arr, element, 0, n - 1);
    cout<<"Pos "<<pos;
    return 0;
}