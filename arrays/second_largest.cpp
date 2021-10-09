#include<iostream>
#include<climits>
using namespace std;

int secondLargest(int arr[], int n)
{
    int s_highest = INT_MIN, highest = arr[0];

    if(n <= 1)
    {
        return s_highest;
    }
    
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > highest)
        {
            s_highest = highest;
            highest = arr[i];
        }

        else if (arr[i] != highest && arr[i] > s_highest)
        {
            s_highest = arr[i];
        }
    }

    return s_highest;
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
    int sl = secondLargest(arr, len);
    cout<<"Second largest is "<<sl;
    return 0;
}