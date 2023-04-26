#include<iostream>
using namespace std;

int firstOccurance(int arr[], int len, int element)
{
    for(int i = 0; i < len; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    return -1;
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
    cout<<"Enter the element you want to search for\n";
    cin>>num;
    int pos = firstOccurance(arr, len, num);
    cout<<"\n"<<pos;
    return 0;
}