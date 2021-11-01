#include<iostream>
#include<climits>
using namespace std;

int altallindex(int arr[], int element, int current, int output[], int &k, int size)
{
    if(current == size)
    {
        return;
    }
    if(arr[current] == element)
    {
        output[k] = current;
        k++;
    }
    altallindex(arr, element, current + 1, output, k, size);
}

int checkIndeces(int arr[], int size, int element, int output[])
{
    // if(size == 0)
    // {
    //     return 0;
    // }
    // int ans = checkIndeces(arr, size - 1, element, output);
    // if(arr[size - 1] == element)
    // {
    //     output[ans] = arr[size - 1];
    //     return ans + 1;
    // }
    // return ans;
    int k = 0;
    altallindex(arr, element, 0, output, k, size);
    return k;
}

int main()
{
    int arr[10], output[10], n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int size = checkIndeces(arr, n, x, output);
    for(int i = 0; i < size; i++)
    {
        cout<<output[i]<<" ";
    }
    return 0;
}