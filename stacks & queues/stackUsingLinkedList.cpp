#include<iostream>
using namespace std;
template <typename type>

class node
{
    public:
    type data;
    node<type> *next;
    node(type data)
    {
        this -> data = data;
        this -> next = nullptr;
    }
};

class stack
{
    node <int> *top;
    int size;
    public:
    stack()
    {
        top = nullptr;
        size = 0;
    }
    int getSize()
    {
        if(top == nullptr)
        {
            return 0;
        }
        return size;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(int element)
    {
        node <int> *newnode = new node<int>(element);
        if(newnode == nullptr)
        {
            cout << "Stack is full\n";
            return;
        }
        newnode -> next = top;
        top = newnode;
        ++size;
    }
    int pop()
    {
        if(isEmpty())
        {
            return -1;
        }
        --size;
        node <int> *temp = top;
        int element = temp -> data;
        top = top -> next;
        delete temp;
        return element;
    }
    int getTop()
    {
        if(isEmpty())
        {
            return -1;
        }
        return top -> data;
    }
    void display()
    {
        node <int> *temp = top;
        while(temp != nullptr)
        {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main()
{
    stack s;
    int choice = 1, opchoice;
    cout << "Enter the operation you want to performe\n";
    while(choice)
    {
        cout << "1.Push\n2.Pop\n3.Size\n4.Top\n5.Display\n6Exit\n";
        cin >> opchoice;
        if(opchoice == 1)
        {
            int data;
            cin >> data;
            while(data != -1)
            {
                s.push(data);
                cin >> data;
            }
            s.display();
        }
        else if(opchoice == 2)
        {
            int data = s.pop();
            cout << data << endl;
        }
        else if(opchoice == 3)
        {
            int size = s.getSize();
            cout << size << endl;
        }
        else if(opchoice == 4)
        {
            int top = s.getTop();
            cout << top << endl;
        }
        else if(opchoice == 5)
        {
            s.display();
        }
        else
        {
            exit(0);
        }
        cout << "Do you want to performe any other operation\n";
        cin >> choice;
        if(!choice)
        {
            break;
        }
    }
    return 0;
}

