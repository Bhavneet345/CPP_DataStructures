#include<iostream>
using namespace std;

void fibo(int n_terms)
{
    int a = 0, b = 1, c;

    for(int i = 0; i <= n_terms; i++)
    {
        cout<<a<<" ";
        c = a + b;
        a = b; 
        b = c;
    }
}

int main()
{
    int n;
    cin>>n;
    fibo(n);
    return 0;
}