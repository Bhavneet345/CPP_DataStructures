#include<iostream>
using namespace std;

class student
{
    public:
    int roll;
    private:
    int age;
    public:
    //setters
    void setAge(int a)
    {
        if(a > 0)
        {
            age = a;
        }
    }
    //getter
    void getAge()
    {
        cout << age;
    }
    void display()
    {
        cout << "Age " << age << " " << "roll number " << roll << endl;
    }
    //constructor called automatically at creation of the object.
    student()
    {
        cout << "Constructor called !" << endl;
    }
    student(int r)
    {
        roll = r;
        cout << "Parameterised constructor called and roll number is " << roll << endl;
    }
};

int main()
{
    student s1 , *s2 = new student(), *s3 = new student(101), s4(102);
    s1.setAge(20), s2 -> setAge(30);
    s1.roll = 001, s2 -> roll = 002;
    s1.display(), s2->display();
    student s5;
    s5.setAge(100), s5.roll = 005;
    // s5 = s1;
    s5.display();
    return 0;
}
