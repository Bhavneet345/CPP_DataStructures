#include<iostream>
using namespace std;

int main()
{
    int n,num = 1;;
    cout<<"Enter the number of rows\n";
    cin>>n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(j <= n-i)
            {
                cout<<" ";
            }
            else
            {
                cout<<num;
                num += 1;
            }
        }
        cout<<endl;
    }

    return 0;
}