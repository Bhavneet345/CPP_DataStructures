#include<iostream>
using namespace std;

bool helper(int *input, int size, int parent)
{
    if(parent >= size)
    {
        return true;
    }
    int left = (2 * parent + 1), right = (2 * parent + 2);
    if(left >= size && right >= size)
    {
        return true;
    }
    if(left < size && right < size)
    {
        if(input[left] > input[parent] || input[right] > input[parent])
        {
            return false;
        }
        return helper(input, size, left) && helper(input, size, right);
    }
    if(input[left] > input[parent])
    {
        return false;
    }
    return helper(input, size, left);
}

bool isMaxHeap(int input[], int n)
{
    return helper(input, n, 0);
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
    if(isMaxHeap(input, n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}