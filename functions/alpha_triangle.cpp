#include<iostream>
using namespace std;

void alpha_triangle(int rows)
{
    int a = 65,b;
    for(int i = 1; i <= rows; i++)
    {
        a = 65;
        
        for(int j = 1; j <= rows - i; j++)
        {
            cout<<" ";
        }

        for(int j = 1; j <= i; j++)
        {
            cout<<(char)a;
            a++;
        }

        b = 65 + (i - 2);
        for(int j = 1; j <= i - 1; j++)
        {
            cout<<(char)b;
            b--;
        }
        cout<<"\n";
    }
}

int main()
{
    int n_rows;
    cin>>n_rows;
    alpha_triangle(n_rows);
    return 0;
}