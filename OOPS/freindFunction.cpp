#include<iostream>
using namespace std;

class car
{
    public:
    void print();
};

class vehicle
{
    private:
    int numtyres;
    public:
    string color;
    friend void car :: print();
};

void car :: print()
{
    vehicle v;
    v.numtyres = 4;
    v.color = "Black";
    cout << v.numtyres << " " << v.color << endl;
}

int main()
{
    car c;
    c.print();
    return 0;
}