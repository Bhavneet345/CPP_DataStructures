#include<iostream>
using namespace std;

void farhenheit_table(int s, int e, int w)
{
    int farh, i;
    for(int i = s; i <= e;)
    {
        farh = (i -32) * (5.0 / 9);
        cout<<i<<"\t"<<farh<<"\n";
        i+=w;
    }
}

int main()
{
    int starting, ending, step;
    cin>>starting>>ending>>step;
    farhenheit_table(starting, ending, step);
    return 0;
}