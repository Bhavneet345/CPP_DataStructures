#include<iostream>
using namespace std;

class DynamicArray
{
    int *arr, pos, size;
    public:
    DynamicArray()
    {
        arr = new int[5];
        pos = 0;
        size = 5;
    }
    DynamicArray(const DynamicArray &d)
    {
        int *newarr = new int[d.size];
        arr = newarr;
        for(int i = 0; i < d.size; i++)
        {
            arr[i] = d.arr[i];
        }
        this -> pos = d.pos;
        this -> size = d.size;
    }
    void addElement(int element)
    {
       if(pos == size)
       {
           int *newarr = new int[2 * size];
           for(int i = 0; i < size; i++)
           {
               newarr[i] = arr[i];
           }
           delete [] arr;
           arr = newarr;
           size *= 2;
       }
       arr[pos] = element;
       ++pos;
    }
    int getElement(int index) const
    {
        if(index >= pos)
        {
            return -1;
        }
        return arr[index];
    }
    void addAtposition(int index, int element)
    {
        if(index >= pos)
        {
            return;
        }
        if(pos == size)
        {
            addElement(element);
            return;
        }
        int i = 0;
        for(i = pos - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = element;
    }
    void changeElement(int index, int element)
    {
        if(index > size || index > pos)
        {
            return;
        }
        arr[index] = element;
    }
    void print() const
    {
        for(int i = 0; i < pos; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray d;
    for(int i = 0; i < 10; i++)
    {
       d.addElement(i);
    }
    d.print();
    d.addAtposition(4, 25);
    d.print();
    DynamicArray d2(d);
    d2.print();
    d2.changeElement(4, 100);
    d2.print();
    d.print();
    return 0;
}