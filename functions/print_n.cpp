#include<iostream>
using namespace std;

void print_num(int n)
{
    for(int i = 1; i <= n; i++)
    {
        cout<<i<<endl;
    }
}

int main()
{
    int num;
    cin>>num;

    print_num(num);
}