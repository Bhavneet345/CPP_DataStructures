#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n_terms,i=1,num,max = INT_MIN, s_max = INT_MIN;

    cin>>n_terms;

    while (i <= n_terms)
    {
        cin>>num;
        if(num > max)
        {
            s_max = max;
            max = num;
        }
        
        else if(num > s_max && num != max)
        {
            s_max = num;
        }
        i++;
    }

    cout<<s_max;
    return 0;
}