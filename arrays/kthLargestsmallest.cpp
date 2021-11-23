#include<iostream>
#include<climits>
using namespace std;

void KlargestSmallest(int arr[], int n, int k)
{
    int temp = INT_MAX, i, check = 0;
    //for kth largest
    for(i = n - 1; n >= 0; i--)
    {
        if(arr[i] < temp)
        {
            check++;
            temp = arr[i];
        }
        if(check == k)
        {
            cout << arr[i] << " ";
            break;
        }
    }
    if(i == -1)
    {
        cout << -1 << " ";
    }
    //for kth smallest
    temp = INT_MIN, check = 0;
    for(i = 0; i < n; i++)
    {
        if(temp < arr[i])
        {
            temp = arr[i];
            check++;
        }
        if(check == k)
        {
            cout << arr[i];
            break;
        }
    }
    if(i == n)
    {
        cout << -1 << " ";
    }
}

int main()
{
    int n, *arr = new int [n], k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    KlargestSmallest(arr, n, k);
    return 0; 
}