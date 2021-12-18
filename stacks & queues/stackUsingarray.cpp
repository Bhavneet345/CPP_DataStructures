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

    int getSize()
    {
        return top;
    }

    void push(int element)
    {
        if(top != capacity)
        {
            arr[top] = element;
            ++top;
        }
        else
        {
            cout << "Stack full\n";
        }
    }

    int pop()
    {
       if(isEmpty())
       {
           cout << "Stack empty\n";
           return -1;
       }
       return arr[--top];
    }

    void display()
    {
        for(int i = 0; i < top; i++)
        {
            cout << arr[i] << " ";
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
    s.push(6); // displayed stack full
    s.display();
    int choice;
    cout << "Do you want to pop an element\n";
    cin >> choice;
    if(choice)
    {
        cout << "Poped element " << s.pop() << endl;
    }
    s.display();
    cout << s.getTop();
    return 0;
}