#include<iostream>
using namespace std;

class Polynomial
{
    public:
    int *degCoeff;
    int capacity;
    
    //default constructor
    Polynomial()
    {
        degCoeff = new int[10]();
        capacity = 10;
    }
    //copy constructor
    Polynomial(const Polynomial &p1)
    {
        int *arr = new int[p1.capacity + 1];
        this -> degCoeff = arr;
        for(int i = 0; i < p1.capacity; i++)
        {
            degCoeff[i] = p1.degCoeff[i];
        }
        this -> capacity = p1.capacity;
    }
    //setcoefficient
    void setCoefficient(int degree, int coeff)
    {
        if(degree < capacity)
        {
            degCoeff[degree] = coeff;
        }
        else
        {
            int *arr = new int[degree + 1];
            for(int i = 0; i < this -> capacity; i++)
            {
                arr[i] = degCoeff[i];
            }
            this -> degCoeff = arr;
            degCoeff[degree] = coeff;
            this -> capacity = degree + 1;
        }
    }
    //+operator
    Polynomial operator+(const Polynomial &p1)
    {
        Polynomial pnew;
        int *arr = new int[(this -> capacity) + (p1.capacity)](), minimum = min((this -> capacity), (p1.capacity));
        for(int i = 0; i < minimum; i++)
        {
            arr[i] = degCoeff[i] + p1.degCoeff[i];
        }
        for(int i = minimum; i < (this -> capacity); i++)
        {
            arr[i] = degCoeff[i];
        }
        for(int i = minimum; i < p1.capacity; i++)
        {
            arr[i] = p1.degCoeff[i];
        }
        pnew.degCoeff = arr;
        pnew.capacity = max(this -> capacity,p1.capacity);
        return pnew;
    }
    //-operator
    Polynomial operator-(const Polynomial &p1)
    {
        Polynomial pnew;
        int *arr = new int[(this -> capacity) + (p1.capacity)](), minimum = min((this -> capacity), (p1.capacity)), 
        maximum = max((this -> capacity), (p1.capacity));
        for(int i = 0; i < minimum; i++)
        {
            arr[i] = degCoeff[i] - p1.degCoeff[i];
        }
        for(int i = minimum; i < (this -> capacity); i++)
        {
            arr[i] = degCoeff[i];
        }
        for(int i = minimum; i < p1.capacity; i++)
        {
            arr[i] = -p1.degCoeff[i];
        }
        pnew.degCoeff = arr;
        pnew.capacity = ((this -> capacity) + (p1.capacity));
        return pnew;
    }
    //*operator
    Polynomial operator*(const Polynomial &p1)
    {
        Polynomial pnew;
        for(int i = 0; i < capacity; i++)
        {
            if(degCoeff[i] ==  0)
            {
                continue;
            }
            for(int j = 0; j < p1.capacity; j++)
            {
                if(p1.degCoeff[j] != 0)
                {
                    int degree = i + j, coeff = degCoeff[i] * p1.degCoeff[j];
                    pnew.setCoefficient(i + j, pnew.degCoeff[i + j] + coeff);
                }
            }
        }
        return pnew;
    }
    //copy assignment operator
    void operator=(const Polynomial &p1)
    {
        int *arr = new int[p1.capacity + 1]();
        for(int i = 0; i < p1.capacity; i++)
        {
            arr[i] = p1.degCoeff[i];
        }
        this -> degCoeff = arr;
        this -> capacity = p1.capacity;
    }
    //==operator
    bool operator==(Polynomial const &p1) const
    {
        int maximum = max(capacity, p1.capacity), minimum = min(capacity, p1.capacity);
        bool check = true;
        for(int i = 0; i < maximum; i++)
        {
            if(degCoeff[i] != 0 || p1.degCoeff[i] != 0)
            {
                if(degCoeff[i] == p1.degCoeff[i])
                {
                    check = true;
                }
                else
                {
                    return false;
                }
            }
        }
        return check;
    }
    //print
    void print()
    {
        for(int i = 0; i < capacity; i++)
        {
            if(degCoeff[i] != 0)
            {
                cout << degCoeff[i] << "x" << i << ' '; 
            }
        }
        cout << endl;
    }
};

int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third == first) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;  
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth == first) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    return 0;
}