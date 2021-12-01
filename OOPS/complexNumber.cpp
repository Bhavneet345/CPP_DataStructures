#include<iostream>
using namespace std;

class ComplexNumber
{
    private:
    int real, imaginary;
    public:
    ComplexNumber(int real, int imaginary)
    {
        this -> real = real;
        this -> imaginary = imaginary;
    }
    void print()
    {
        cout << real << " + " << "i" << imaginary << endl;
    }
    void add(ComplexNumber c2)
    {
        real = real + c2.real;
        imaginary = imaginary + c2.imaginary;
    }
    void multiply(const ComplexNumber &c2)
    {
        int temp = imaginary;
        imaginary = (imaginary * c2.real) + (real * c2.imaginary);
        real *= c2.real;
        real -= (temp * c2.imaginary); 
    }
};

int main()
{
    int real1, imaginary1, real2, imaginary2;
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    ComplexNumber c1(real1, imaginary1), c2(real2, imaginary2);
    int choice;
    cin >> choice;
    if(choice == 1)
    {
        c1.add(c2);
        c1.print();
    }
    else if(choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }
    else
    {
        cout << "Invalid choice\n";
    }
    return 0;
}