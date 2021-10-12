#include<iostream>
#include<climits>
using namespace std;

void insertionSort(int arr[], int len)
{
    int j;
    for(int i = 1; i < len; i++)
    {
        int temp = arr[i];
        
        for(j = i - 1; j >= 0; j--)
        {
            if(temp < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

void klargest(int arr[], int len, int k)
{
    int mn = INT_MAX, z = len - 1, count = 0, flag = 0; 
    while (z >= 0)
    {
        if(mn > arr[z])
        {
            mn = arr[z];
            count++;
        }

        if(count == k)
        {
            flag = 1;
            cout<<arr[z]<<" ";
            break;
        }
        z--;
    }

    if(flag == 0)
    {
        cout<<-1<<" ";
    }

    mn = INT_MIN, z = 0, count = 0, flag = 0;

    while (z < len)
    {
        if(mn < arr[z])
        {
            mn = arr[z];
            count++;
        }

        if(count == k)
        {
            flag = 1;
            cout<<arr[z]<<" ";
            break;
        }
        z++;
    }

    if(flag == 0)
    {
        cout<<-1<<" ";
    }
}

int main()
{
    int arr[100], num, len;
    cin>>len;
    cout<<"Enter the elements\n";
    for(int i = 0; i < len; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the kth number\n";
    cin>>num;
    klargest(arr, len, num);
    return 0;
}