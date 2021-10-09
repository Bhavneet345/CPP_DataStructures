#include<iostream>
using namespace std;

int main()
{
    int num,i,j;

    cout<<"Enter number of rows\n";
    cin>>num;

    for(i = 1; i <= num; i++)
    {
        char alpha = 65;    //char alpha = 'A' + j - 1; and cout<<alpha; inside second loop;
        for (j = 1; j <= num; j++)
        {
            cout<<(char)alpha;
            alpha ++;   
        }
        cout<<endl;
    }

    return 0;
}