#include<iostream>
using namespace std;

void PrintSubset(int input[], int size, int output[], int osize)
{
    if(size == 0)
    {
        for(int i = 0; i < osize; i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    PrintSubset(input + 1, size - 1, output, osize);
    int smalloutput[10000], i = 0;
    for(i = 0; i < osize; i++)
    {
        smalloutput[i] = output[i];
    }
    smalloutput[i] = input[0];
    PrintSubset(input + 1, size - 1, smalloutput, osize + 1);
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int output[10000];
    PrintSubset(arr, n, output, 0);
    return 0;
}