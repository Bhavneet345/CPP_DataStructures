#include<iostream>
using namespace std;

int main()
{
    int arr[1000000], sum = 0, n;
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for(int i = 0; i <n; i++)
    {
        sum = sum + arr[i];
    }

    cout<<"Sum is "<<sum;
    return 0;
}