#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int arr[10], max = INT_MIN, n;
    cin>>n;

    for(int i = 0; i <= n-1; i++)
    {
        cin>>arr[i];
    }

    for(int i = 0; i <= n-1; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout<<"Maximum element is "<<max;
    return 0;
}