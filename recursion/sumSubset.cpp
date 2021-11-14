#include<iostream>
using namespace std;

void printSum(int input[], int size, int output[], int osize, int k)
{
    if(size == 0)
    {
        if(k == 0)
        {
            for(int i = 0; i < osize; i++)
            {
                cout<<output[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    int smalloutput[10000], i = 0;
    printSum(input + 1, size - 1, output, osize, k);
    for(i = 0; i < osize; i++)
    {
        smalloutput[i] = output[i];
    }
    smalloutput[i] = input[0];
    printSum(input + 1, size - 1, smalloutput, osize + 1, k - input[0]);
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
    int output[10000], element;
    cin >> element;
    printSum(arr, n, output, 0, element);
    return 0;
}
