#include<iostream>
using namespace std;

int minCount(int num)
{
    if(num == 0)
    {
        return 0;
    }
    else if(num == 1)
    {
        return 1;
    }
    else if(num == 2)
    {
        return 2;
    }
    int *saved = new int[num + 1];
    saved[0] = 0;
    saved[1] = 1;
    saved[2] = 2;
    for(int i = 3; i <= num; i++)
    {
        int minimum = INT_MAX;
        for(int j = 1; j * j <= i; j++)
        {
            int ans = i - (j * j);
            saved[i] = min(minimum, saved[ans]);
            minimum = saved[i];
        }
        saved[i] += 1;
    }
    return saved[num];
}

int main()
{
    int num;
    cin >> num;
    cout << minCount(num);
    return 0;
}