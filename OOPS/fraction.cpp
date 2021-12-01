#include<iostream>
using namespace std;

class Fraction
{
    private:
    int numerator, denominator, gcd;

    public:

    Fraction(int numerator, int denominator)
    {
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void print()
    {
        cout << this -> numerator << "/" << this -> denominator << endl;
    }

    void simplify()
    {
        gcd = 0;
        for(int i = 2; i <= min(numerator, denominator); i++)
        {
            if(numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }
    }

    void add(const Fraction &f2)
    {
        int lcm = denominator * f2.denominator;
        int res1 = lcm / denominator, res2 = lcm / f2.denominator;
        int res = (numerator * res1) + (f2.numerator * res2);
        numerator = res, denominator = lcm;
        //for simplification find GCD
        simplify();
        numerator /= gcd;
        denominator /= gcd;
    }

    void multiply(Fraction const &f2)
    {
        this -> numerator = this -> numerator * f2.numerator;
        denominator = denominator * f2.denominator;
        simplify();
        numerator /= gcd;
        denominator /= gcd;
    }
};

int main()
{
    Fraction f1(10,2), f2(20,5);
    f1.print(), f2.print();
    f1.add(f2);
    f1.multiply(f2);
    f1.print();
    return 0;
}