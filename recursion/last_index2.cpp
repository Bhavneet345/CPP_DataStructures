#include<iostream>
using namespace std;

int lastIndex(int arr[], int size, int element)
{
    if(size == 0)
    {
        return -1;
    }
    int ans = lastIndex(arr + 1, size - 1, element);
    if(ans != -1)
    {
        return ans + 1;
    }
    if(arr[0] == element)
    {
        return 0;
    }
    return -1;
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int element;
    cout<<"Enter the element you want to search\n";
    cin>>element;
    int index = lastIndex(arr, n, element);
    cout<<"Index "<<index;
    return 0;
}