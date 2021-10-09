#include<iostream>
using namespace std;

int main()
{
    int n,i = 1,j = 1, res = 1;

    cout<<"Enter the number of rows\n";
    cin>>n;
    cout<<"\n";

    while(i <= n)
    {
        j = 1;
        
        while (j <= i)
        {
            cout<<res<<" ";
            res = res + 1;
            j = j + 1;
        }
    
    i = i+1;
    cout<<endl;   
    }

    return 0;
}