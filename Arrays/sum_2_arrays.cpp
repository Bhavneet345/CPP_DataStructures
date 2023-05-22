#include<iostream>
using namespace std;

void reverse(int arr[], int len)
{
    int i = 0, j = len - 1;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
void sum2arrays(int arr1[], int size1, int arr2[], int size2)
{
    int i = 0, j = 0, arr[100], k = max(size1, size2), carry = 0;

    for(int i = size1 - 1, j = size2 - 1; i >= 0, j >= 0; i--,j--)
    {
        int num = arr1[i] + arr2[j]  + carry;
        int rem = num % 10;
        carry = num / 10;
        arr[k] = rem;
        k--;
    }

    while(i >= 0)
    {
        int num = arr1[i] + carry;
        int rem = num % 10;
        carry = num / 10;
        arr[k] = rem;
        k--;   
        i--;
    }

    
    while(j >= 0)
    {
        int num = arr2[j] + carry;
        int rem = num % 10;
        carry = num / 10;
        arr[k] = rem;
        k--;   
        j--;
    }

    arr[0] = carry;

    int max_size = max(size1, size2);
    
    for(int j = 0; j <= max_size ; j++)
    {
        cout<<arr[j]<<" ";
    }
}

int main()
{
    int arr1[100], arr2[100], n1, n2;
    cin>>n1;
    cin>>n2;
    cout<<"Enter the elements of arr1\n";
    for(int i = 0; i < n1; i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the elements of arr2\n";
    for(int i = 0; i < n2; i++)
    {
        cin>>arr2[i];
    }
    sum2arrays(arr1, n1, arr2, n2);
    return 0;
}