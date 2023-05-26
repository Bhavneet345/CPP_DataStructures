#include<iostream>
using namespace std;

int triplet(int arr[], int n, int x)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(arr[i] + arr[j] + arr[k] == x)
                {
                    ++count;
                }
            }
        }
    }
    return count;
}

int main()
{
    int arr[100], n, element;
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i = 0 ; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element\n";
    cin>>element;
    int count = triplet(arr, n, element);
    cout<<"Number of triplets "<<count;
    return 0;
}