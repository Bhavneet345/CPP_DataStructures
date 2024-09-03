#include<iostream>
using namespace std;

long stairCase(int num)
{
    if(num <= 1)
    {
        return 1;
    }
    else if(num == 2)
    {
        return 2;
    }
    long *steps = new long[num + 1];
    steps[0] = 1, steps[1] = 1, steps[2] = 2;
    for(int i = 3; i <= num; i++)
    {
        steps[i] = steps[i - 1] + steps[i - 2] + steps[i - 3];
    }
    return steps[num];
}

int main()
{
    int num;
    cin >> num;
    cout << stairCase(num);
    return 0;
}