#include<iostream>
using namespace std;

void fibo_triangle(int n_rows)
{
    int a = 0, b = 1, c = 0;
    for(int i = 1; i <= n_rows; i++)
    {
        a = 0, b = 1, c = 0;
        for(int j = 1; j <= i; j++)
        {
            cout<<b<<"\t";
            c = a + b;
            a = b;
            b = c;
        }
        cout<<"\n";
    }
}

int main()
{
    int n_rows;
    cin>>n_rows;
    fibo_triangle(n_rows);
    return 0;
}
