#include<iostream>
using namespace std;

int sum(int num)
{
    if(num == 0)
    {
        return 0;
    }
    int ans = num % 10;
    return ans + sum(num / 10);
}

int main()
{
    int num;
    cin>>num;
    int ans = sum(num);
    cout<<ans;
    return 0;
}