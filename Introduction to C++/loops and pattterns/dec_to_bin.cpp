#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    float num,one = 1, zero = 0,temp;

    cin>>num;

    if(num == 0)
    {
        cout<<zero;
    }

    else
    {
        for(int i = 0; pow(2,i) <= num; i++)
        {
            temp++;
        }
        
        int highest = temp - 1;
        num = num - pow(2,highest);
        cout<<one;
        
        for(int j = highest - 1 ; j >= 0; j--)
        {
            if(pow(2,j) <= num)
            {
                num = num - pow(2,j);
                cout<<one;
            }
        
            else
            {
                cout<<zero;
            }
        }
    }
    
    return 0;
}