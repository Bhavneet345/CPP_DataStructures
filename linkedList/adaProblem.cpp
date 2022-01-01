#include<iostream>
#include<deque>
using namespace std;

class node
{
    public:
    node *next, *prev;
    int data;
    node(int data)
    {
        this -> next = nullptr;
        this -> prev = nullptr;
        this -> data = data;
    }
};

class Adathings
{
    node *head, *tail;
    bool flag, called;
    public:
    Adathings()
    {
        head = nullptr;
        tail = nullptr;
        flag = false;
        called = false;
    }
    void back()
    {
        if(!flag || called)
        {
            if(head == nullptr)
            {
                cout << "No job for Ada?" << endl;
                return;
            }
            cout << tail -> data << endl;
            if(tail -> prev != nullptr)
            {
                node *temp = tail;
                tail = tail -> prev;
                tail -> next = nullptr;
                delete temp;
            }
            else
            {
                tail = head = nullptr;
            }
        }
        else
        {
            called = true;
            front();
        }
        return;
    }
    void front()
    {
        if(!flag || called)
        {
            if(head == nullptr)
            {
                cout << "No job for Ada?" << endl;
                return;
            }
            cout << head -> data << endl;
            node *temp = head;
            head = head -> next;
            delete temp;
            return;
        }
        else
        {
            called = true;   
            back();
        }
    }
    void reverse()
    {
        if(head == nullptr)
        {
            cout << "No job for Ada?" << endl;
            return;   
        }
        if(head -> next == nullptr)
        {
            return;
        }
        if(flag)
        {
            called = false;
            flag = false;
        }
        else
        {
            flag = true;
        }
        return;
    }
    void pushBack(int element)
    {
        if(head == nullptr)
        {
            head = tail = new node(element);
            return;
        }
        tail -> next = new node(element);
        tail = tail -> next;
    }
    void pushFront(int element)
    {
        if(head == nullptr)
        {
            head = tail = new node(element);
            return;
        }
        node *newnode = new node(element);
        newnode -> next = head;
        head = newnode;
        return;
    }
};

int main()
{
    Adathings ada;
    int queries, data;
    string choice;
    cin >> queries;
    while(queries)
    {
        cin >> choice;
        if(choice == "toFront")
        {
            cin >> data;
            ada.pushFront(data);
        }
        else if(choice == "front")
        {
            ada.front();
        }
        else if(choice == "back")
        {
            ada.back();
        }
        else if(choice == "reverse")
        {
            ada.reverse();
        }
        else if(choice == "push_back")
        {
            cin >> data;
            ada.pushBack(data);
        }
        --queries;
    }
    return 0;
}