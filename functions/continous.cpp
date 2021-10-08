#include<iostream>
using namespace std;

bool continous(int num)
{
    int prev,current;
    bool isdec = true;
    cin>>prev;
    for(int i = 2; i <= num; i++)
    {
        cin>>current;

        if(current == prev)
        {
            return false;
        }
        
        if(current < prev)
        {
            if(isdec == false)
            {
                return false;
            }
        }

        else
        {
            isdec = false;
        }
    }
    return true;
}

int main()
{
    int n_terms;
    cin>>n_terms;

    if(continous(n_terms))
    {
        cout<<"true\n";
    }

    else
    {
        cout<<"false\n";
    }

    return 0;
}