#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int val)
{
    int start = 0, end = n - 1, mid;
    
    while(start <= end)
    {
        mid = (start + end) / 2;

        if(arr[mid] > val)
        {
            end = mid - 1;
        }

        else if(arr[mid] < val)
        {
            start = mid + 1;
        }

        else
        {
            break;
        }
    }
    if(arr[mid] == val)
    {
        return mid;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int arr[100], n, val;
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element you want to search for\n";
    cin>>val;
    int pos = binarySearch(arr, n, val);
    cout<<"Element found at "<<pos;
    return 0;
}




