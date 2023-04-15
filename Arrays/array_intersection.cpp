#include<iostream>
#include<climits>
using namespace std;

void intersection(int arr1[], int arr2[], int n, int m)
{
    int arr[100], pos = 0;
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr1[i] == arr2[j])
            {
                arr[pos] = arr1[i];
                arr2[j] = INT_MIN;
                ++pos;
                break;
            }
        }
    }   

    cout<<"Elements are as follows\n";
    for(int i = 0; i < pos; i++)
    {
        cout<<arr[i]<<" ";
    } 

    return;
}

int main()
{
    int n,m,arr1[100],arr2[100];
    cin>>n;
    cin>>m;
    
    cout<<"Enter elements in array 1\n";
    for(int i = 0; i < n; i++)
    {
        cin>>arr1[i];
    }
    
    cout<<"Enter elements in array 2\n";
    for(int i = 0; i < m; i++)
    {
        cin>>arr2[i];
    }

    intersection(arr1, arr2, n, m);
    return 0;
}

