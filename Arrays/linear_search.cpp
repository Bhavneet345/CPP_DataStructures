#include<iostream>
using namespace std;

int linear_search(int arr[], int n, int element)
{
    int pos;
    bool found = false;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == element)
        {
            found = true;
            pos = i;
            break;
        }
    }
    if(found)
    {
        return pos;
    }
    else
    {
        return -1;
    }
}

