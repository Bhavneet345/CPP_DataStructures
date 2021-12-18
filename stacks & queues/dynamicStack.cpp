#include<iostream>
using namespace std;

class stack
{
    int *arr, top, capacity;
    public:
    stack(int totalsize)
    {
        arr = new int[totalsize];
        capacity = totalsize;
        top = 0;
    }
    bool isEmpty()
    {
        return top == 0;
    }
    int getTop()
    {
        if(!isEmpty())
        {
            return arr[top - 1];
        }
        return -1;
    }
    void push(int element)
    {
        if(top == capacity)
        {
            int *newarr = new int[2 * capacity];
            for(int i = 0; i < top; i++)
            {
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            capacity *= 2;
        }
        arr[top] = element;
        ++top; 
    }
    int pop()
    {
        if(!isEmpty())
        {
            return arr[--top];
        }
        return -1;
    }
    void display()
    {
        for(int i = 0; i < top; i++)
        {
            cout << arr[i]<< " ";
        }
        cout << endl;
    }
};

int main()
{
    int size, data;
    cin >> size;
    stack s(size);
    for(int i = 0; i < size; i++)
    {
        cin >> data;
        s.push(data);
    }
    s.display();
    int choice;
    cout << "Do you want to pop(1) an element or insert(2) a new element\n";
    cin >> choice;
    if(choice == 1)
    {
        cout << "Poped element " << s.pop() << endl;
    }
    else if(choice == 2)
    {
        cin >> size;
        for(int i = 0; i < size; i++)
        {
            cin >> data;
            s.push(data);
        }
    }
    s.display();
    cout << s.getTop();
    return 0;
}