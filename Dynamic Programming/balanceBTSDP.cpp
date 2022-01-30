#include<iostream>
#include<cmath>
using namespace std;

int  balancedBTs(int h)
{
    if(h <= 1)
    {
        return 1;
    }
    else if(h == 2)
    {
       return 3;
    }
    int mod = (int)(pow(10, 9) + 7);
    int *saved = new int[h + 1];
    saved[0] = 1;
    saved[1] = 1;
    saved[2] = 3;
    for(int i = 3; i <= h; i++)
    {
        int h1 = saved[i - 1], h2 = saved[i - 2];
        int temp1 = (int)(((long)(h1) * h1) % mod);
        int temp2 = (int)((2 * (long)(h1) * h2) % mod);
        saved[i] = (temp1 + temp2) % mod;
    }
    return saved[h];
}

int main()
{
    int num;
    cin >> num;
    cout << balancedBTs(num);
    return 0;
}