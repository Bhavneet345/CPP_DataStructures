#include<iostream>
#include<cmath>
using namespace std;

int getAllwayshelper(int a, int b, int current)
{
    if(a == 0)
    {
        return 1;
    }
    else if(a < b)
    {
        return 0;
    }
    int count = 0;
    for(int i = current + 1; pow(i, b) <= a; i++)
    {
        count += getAllwayshelper(a - pow(i, b), b, i);
    }
    return count;
}

int getAllways(int a, int b)
{
    return getAllwayshelper(a, b, 0);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllways(a, b);
    return 0;
}