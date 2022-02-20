#include<iostream>
using namespace std;

class vehicle
{
    public:
    string color;
    //pure virtual function
    virtual void print() = 0;
};

class car : public vehicle
{
    public:
    int numtyres;
    void print()
    {
        cout << numtyres << endl;
    }
};

int main()
{
    // vehicle v; error because abstrac class due to pure virtual function
    car c;
    c.numtyres = 4;
    c.print();
    return 0;
}