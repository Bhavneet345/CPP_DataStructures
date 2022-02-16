#include<iostream>
using namespace std;

class vehicle
{
    public:
    string color;
    private:
    int maxspeed;
    protected:
    int numtyres;
};

class car : public vehicle
{
    public:
    int numgears;
    
    void setNumtyres(int num)
    {
        numtyres = num;
    }
    void print()
    {
        cout << color << " " << numtyres << " " << numgears;
    }
};

class honda : public car
{
    public:
    void printhonda()
    {
        print();
    }
};

int main()
{
    car c;
    c.color = "black";
    c.numgears = 6;
    c.setNumtyres(4);
    c.print();
    honda h;
    cout << endl;
    h.color = "red";
    h.numgears = 6;
    h.setNumtyres(4);
    h.printhonda();
    return 0;
}