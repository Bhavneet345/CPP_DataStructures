#include<iostream>
using namespace std;

void selectionSort(int arr[], int len)
{
    int min, min_pos;
    for(int i = 0; i < len - 1; i++)
    {
        min = arr[i];
        min_pos = i;
        for(int j = i+1; j <= len - 1; j++)
        {
            if(arr[j] < min)
            {
                min_pos = j;
                min = arr[j];
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_pos];
        arr[min_pos] = temp;
    }
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
    cout << "Before sorting array elements - \n";
    for(int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    selectionSort(arr, len);
    cout << "\nAfter applying shell sort, the array elements are - \n";
    for(int i = 0; i < len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout << "\nMade By - Bhvaneet Singh\n";
    cout << "Roll No. 02513202720";
    return 0;
}