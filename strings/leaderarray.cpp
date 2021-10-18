#include<iostream>
using namespace std;

void leaderArray(int arr[], int len)
{
    int leaders[100], pos = 0;
    bool leader = true;
    for(int i = 0; i < len; i++)
    {
        leader = true;
        for(int j = i + 1; j < len; j++)
        {
            if(arr[i] < arr[j])
            {
                leader = false;
                break;
            }
        }
        if(leader)
        {
            leaders[pos] = arr[i];
            pos++;
        }
    }
    for(int i = 0; i < pos; i++)
    {
        cout<<leaders[i]<<" ";
    }
}

int main()
{
    int arr[1000], len;
    cin>>len;
    for(int i = 0; i < len; i++)
    {
        cin>>arr[i];
    }
    leaderArray(arr, len);
    return 0;
}
