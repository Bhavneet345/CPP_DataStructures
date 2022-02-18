#include<iostream>
using namespace std;

void test(int a)
{
    cout << a << endl;
    return;
}

void test(int a, int b)
{
    cout << a << " " << b << endl;
    return;
}

int main()
{
    test(2);
    test(2, 3);
    return 0;
}