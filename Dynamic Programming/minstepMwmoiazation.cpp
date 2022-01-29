#include<iostream>
using namespace std;

int minStepshelper(int n, int *saved)
{
    if(n == 1)
    {
        return 0;
    }
    if(n <= 3)
    {
        return 1;
    }
    int a = saved[n - 1], b = saved[n / 2], c = saved[n / 3];
    if(a == INT_MAX)
    {
        a = minStepshelper(n - 1, saved);
        saved[n - 1] = a;
    }
    if(n % 2 == 0 && b == INT_MAX)
    {
        b = minStepshelper(n / 2, saved);
        saved[n / 2] = b;
    }
    if(n % 3 == 0 && c == INT_MAX)
    {
        c = minStepshelper(n / 3, saved);
        saved[n / 3] = c;
    }
    int res = min(a, min(b, c)) + 1;
    saved[n] = res;
    return res;
}

int countStepsToOne(int n)
{
    int *saved = new int[n + 1];
    for(int i = 0; i <= n; i++)
    {
        saved[i] = INT_MAX;
    }
    return minStepshelper(n, saved);
}

int main()
{
    int n;
    cin >> n;
    cout << countStepsToOne(n);
    return 0;
}