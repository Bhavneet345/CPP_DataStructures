#include<iostream>
using namespace std;

int lastIndex(int arr[], int size, int element)
{
    if(arr[size - 1] == element)
    {
        return (size - 1);
    }

    else if(size > 1)
    {
        int ans = lastIndex(arr, size - 1, element);
        if(ans != -1)
        {
            return ans;
        }
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