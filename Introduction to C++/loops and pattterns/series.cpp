#include<iostream>
using namespace std;

int main()
{
    int n_terms,temp,num;
    bool check = true;

    cin>>n_terms;
    cin>>temp;

    for(int i = 2; i <= n_terms; i++)
    {
        cin>>num;
        if(num == temp)
        {
            cout<<"false\n";
            return 0;
        }
        if(num < temp)
        {
            if(check == false)
            {
                cout<<"false\n";
                return 0;
            }
        }
        else
        {
            if(check)
            {
                check = false;
            }
        }
    temp = num;
    }
    cout<<"true\n";
}