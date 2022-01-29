#include<iostream>
using namespace std;

//memoization approach followed to save the previous ans for later use
int helper(int n, int *saved)
{
    if(n <= 1)
    {
        return n;
    }
    if(saved[n] != -1)
    {
        return saved[n];
    }
    int a = helper(n - 1, saved);
    int b = helper(n - 2, saved);
    saved[n] = a + b;
    return saved[n];
}

int findFibonacci(int n)
{
    int *saved = new int[n + 1];
    for(int i = 0; i <= n; i++)
    {
        saved[i] = -1;
    }
    return helper(n, saved);
}

int main()
{
    int n;
    cin >> n;
    cout << findFibonacci(n);
    return 0;
}