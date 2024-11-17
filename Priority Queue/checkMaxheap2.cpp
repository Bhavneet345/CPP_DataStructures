#include<iostream>
using namespace std;

bool isMaxheap(int *input, int size)
{
    for(int i = 0; (2 * i) + 1 < size; i++)
    {
        int left = (2 * i) + 1, right = (2 * i) + 2;
        if(input[left] > input[i])
        {
            return false;
        }
        if(right < size && input[right] > input[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    if(isMaxheap(input, n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}