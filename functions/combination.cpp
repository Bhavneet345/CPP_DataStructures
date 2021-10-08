#include<iostream>
using namespace std;

int factorial(int num)
{
    int i = 1, res = 1;
    for(;i <= num; i++)
    {
        res = res * i;
    }
    return res;
}

int main()
{
    int n,r;
    cin>>n;
    cin>>r;

    int res_n = factorial(n);
    int res_r = factorial(r);
    int res_n_r = factorial(n - r);

    cout<<"Number of combinations are "<<res_n / (res_r * res_n_r);

    return 0;
}