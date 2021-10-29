#include<iostream>
using namespace std;

int countZeros(int num)
{
    int ans = 0;
    if(num % 10 == 0)
    {
        ans = 1;
    }
    if(num / 10 != 0)
    {
        ans += countZeros(num / 10);
    }
    return ans;
}

int main()
{
    int num;
    cin>>num;
    int zeros = countZeros(num);
    cout<<zeros;
    return 0;
}