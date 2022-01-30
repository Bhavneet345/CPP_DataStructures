#include<iostream>
#include<cmath>
using namespace std;

int balancedBTs(int h)
{
    if(h <= 1)
    {
        return 1;
    }
    int mod = (int)(pow(10, 9) + 7);
    int h1 = balancedBTs(h - 1), h2 = balancedBTs(h - 2);
    int temp1 = (int)(((long)(h1) * h1) % mod);
    int temp2 = (int)((2 * (long)(h1) * h2) % mod);
    int ans = (temp1 + temp2) % mod;
    return ans;
}

int main()
{
    int num;
    cin >> num;
    cout << balancedBTs(num);
    return 0;
}