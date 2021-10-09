#include<iostream>
using namespace std;


int main()
{
    int num,res,i;
    int k,j,n;
    
    cout<<"Enter number of rows\n";
    cin>>num;
    
    while(i <= num)
    {
        k = 1;
        
        while(k <= num-i)
        {
            cout<<" ";
            k = k + 1; 
        }
        
        j = 1;
        n = i;
        while(j <= i)
        {
            cout<<n;
            j = j + 1;
            n = n + 1;
        }
        cout<<endl;
        i = i + 1;
    }
    return 0;
}