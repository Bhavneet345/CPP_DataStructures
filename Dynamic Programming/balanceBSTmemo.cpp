#include<iostream>
#include<cmath>
using namespace std;

int mod = (int)(pow(10, 9) + 7);

int balancedBT(int *saved, int n)
{
    if(n <= 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 3;
    }
    else if(saved[n] != -1)
    {
        return saved[n];
    }
    int h1 = balancedBT(saved, n - 1);
    int h2 = balancedBT(saved, n - 2);
    int temp1 = (int)(((long)h1 * h1) % mod);
    int temp2 = (int)((2 * (long)h1 * h2) % mod);
    saved[n] = (temp1 + temp2) % mod;
    return saved[n];
}

int main()
{
    int num;
    cin >> num;
    int *saved = new int[num + 1];
    for(int i = 0; i <= num; i++)
    {
        saved[i] = -1;
    }
    cout << balancedBT(saved, num);
    return 0;
}