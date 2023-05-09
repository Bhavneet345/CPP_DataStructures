#include<iostream>
#include<climits>
using namespace std;

int pair_sum(int arr[], int n, int x)
{
    int count = 0;
    bool check = false;
    for(int i = 0; i < n; i++)
    {
        check = false;
        for(int j =  0; j < n; j++)
        {
            if(arr[i] + arr[j] == x && i != j)
            {
                check = true;
                count++;
            }
        }
        if(check)
        {
            arr[i] = INT_MIN;
        }
    }
    return count;
}
int main()
{
    int arr[100], n, element;
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the element\n";
    cin>>element;
    int count = pair_sum(arr, n, element);
    cout<<"Number of pairs are "<<count;
    return 0;
}