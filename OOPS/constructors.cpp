#include<iostream>
using namespace std;

class student
{
    public:
    int rollnumber, age;
    //default parameter
    student()
    {
        cout << "Default constructor called !\n";
    }
    //parameterised constructor
    student(int roll)
    {
        cout << "Parameterised constructor1 called\n";
        rollnumber = roll;
    }
    student(int rollnumber, int age)
    {
        cout << "Parameterised constructor2 called\n";
        this -> rollnumber = rollnumber;
        this -> age = age;
    }
    void display()
    {
        cout << "Roll number is " << rollnumber << " age is " << age << endl;
    }
    //Destructtor
    ~student()
    {
        cout<<"Destructor called\n";
    }
};

int main()
{
    student s1, s2(20), *s3 = new student(101,30);
    s1.display();
    s2.display();
    s3 -> display();
    delete(s3);
    //copy constructor
    student *s4 = new student(*s3);
    s4->display();
    delete(s4);
    //copy assignment operator 
    student s5;
    s5 = *s3;
    s5.display();
    return 0;
}