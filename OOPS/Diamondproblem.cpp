#include<iostream>
using namespace std;

class vehicle
{
    public:
    vehicle(int x)
    {
        cout << "Vehicle Default contructor\n";
    }
    string color;
    private:
    int maxspeed;
    protected:
    int numtyres;
};

class car : virtual public vehicle
{
    public:
    int numgears;
    car(int x) : vehicle(x)
    {
        cout << "Car default\n";
    }
    void setNumtyres(int num)
    {
        numtyres = num;
    }
    void print()
    {
        cout << color << " " << numtyres << " " << numgears;
    }
};

class truck : virtual public vehicle
{
    public:
    int numgears;
    truck(int x) : vehicle(x)
    {
        cout << "Truck default\n";
    }
    void setNumtyres(int num)
    {
        numtyres = num;
    }
    void print()
    {
        cout << color << " " << numtyres << " " << numgears;
    }   
};

class bus : public car, public truck
{
    public:
    int numgears;
    bus(int x) : car(x), truck(x), vehicle(x)
    {
        cout << "Bus default\n";
    }
    void setNumtyres(int num)
    {
        numtyres = num;
    }
    void print()
    {
        cout << color << " " << numtyres << " " << numgears;
    }   
};

int main()
{
    car c(5);
    c.color = "black";
    c.numgears = 6;
    c.setNumtyres(4);
    c.print();
    return 0;
}