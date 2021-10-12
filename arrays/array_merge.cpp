#include<iostream>
using namespace std;

void merge(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0, j = 0, k = 0, arr_new[1000];

    while(i < size1 && j < size2)
    {
        if(arr1[i] < arr2[j])
        {
            arr_new[k] = arr1[i];
            i++;
            k++;
        }

        else
        {
            arr_new[k] = arr2[j];
            j++;
            k++;   
        }
    }

    while (i < size1)
    {
        arr_new[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr_new[k] = arr2[j];
        j++;
        k++;
    }

    for(int j = 0; j < k ; j++)
    {
        cout<<arr_new[j]<<" ";
    }
}

int main()
{
    int arr1[100], arr2[100], len1, len2;
    cin>>len1;
    cin>>len2;
    cout<<"Enter the element for arr1\n";
    
    for(int i = 0; i < len1; i++)
    {
        cin>>arr1[i];
    }
    
    cout<<"Enter the element for arr2\n";
    for(int i = 0; i < len2; i++)
    {
        cin>>arr2[i];
    }

    merge(arr1, len1, arr2, len2);

    return 0;
}