#include<iostream>
using namespace std;

int countStepsToOne(int n)
{
    if(n == 1)
    {
        return 0;
    }
    if(n <= 3)
    {
        return 1;
    }
    int *saved = new int[n + 1];
    saved[0] = 0, saved[1] = 0, saved[2] = 1, saved[3] = 1;
    for(int i = 4; i <= n; i++)
    {
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        a = saved[i - 1];
        if(i % 2 == 0)
        {
            b = saved[i / 2];
        }
        if(i % 3 == 0)
        {
            c = saved[i / 3];
        }
        int res = min(a, min(b, c)) + 1;
        saved[i] = res;
    }
    return saved[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countStepsToOne(n);
    return 0;
}