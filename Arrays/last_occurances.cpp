#include<iostream>
using namespace std;

int lastOccurance(int arr[], int len, int element)
{
    int pos;
    bool found = false;
    for(int i = 0; i < len; i++)
    {
        if(arr[i] == element)
        {
            found = true;
            pos = i;
        }
    }

    if(found)
    {
        return pos;
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
    int pos = lastOccurance(arr, len, num);
    cout<<"\n"<<pos;
    return 0;
}