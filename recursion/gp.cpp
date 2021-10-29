#include<iostream>
#include<cmath>
using namespace std;

double geometricSum(int k)
{
    if(k == 0)
    {
        return 1;
    }
    double sum = 1 / pow(2, k);
    return sum + geometricSum(k - 1);
}

int main()
{
    int num;
    cin>>num;
    double sum = geometricSum(num);
    cout<<"\n"<<sum;
    return 0;
}