#include<iostream>
using namespace std;

void arrange(int arr[], int len)
{
    int i = 0, count = -1;
    for(i = 1; i <= len; i += 2)
    {
        ++count;
        arr[count] = i;
    }

    if(len % 2 == 0)
    {
        i = i - 1;
    }

    else
    {
        i = i - 3;
    }

    for(int j = i; j >= 2; j -= 2)
    {
        arr[count + 1] = j;
        count++;
    }
    cout<<"Following are the elements\n";
    for(int i = 0; i < len; i++)
    {
        cout<<arr[i]<<"\n";
    }
}

int main()
{
    int len, a[100];
    cin>>len;
    arrange(a, len);
    return 0;
}