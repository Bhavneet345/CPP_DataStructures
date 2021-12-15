#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next, *random;
    node(int data)
    {
        this -> data = data;
        this -> next = nullptr;
        this -> random = nullptr;
    }
};

node* takeinput()
{
    int data;
    cin >> data;
    node *head = nullptr, *tail = nullptr;
    while(data != -1)
    {
        if(head == nullptr)
        {
            head = tail = new node(data);
        }
        else
        {
            tail -> next = new node(data);
            tail = tail -> next;
        }
        cin >> data;
    }
    return head;
}

node *cloneLL(node *head)
{
    node *current = head, *fwd = nullptr;
    //making copy of each node
    while(current != nullptr)
    {
        fwd = current -> next;
        current -> next = new node(current -> data);
        current -> next -> next = fwd;
        current = fwd;
    }
    current = head;
    //manage random pointers
    while(current != nullptr)
    {
        if(current -> next != nullptr)
        {
            if(current -> random != nullptr)
            {
                current -> next -> random = current -> random -> next;
            }
            else
            {
                current -> next -> random = current -> random;
            }
            current = current -> next -> next;
        }
        else
        {
            current = current -> next;
        }
    }
    //differntiating the two list
    node *copy = nullptr, *original = head;
    if(head != nullptr)
    {
        copy = head -> next;
    }
    node *temp1 = copy;
    while(temp1 != nullptr && original  != nullptr)
    {
        if(original -> next != nullptr)
        {
            original -> next = original -> next -> next;
        }
        if(copy -> next != nullptr)
        {
            copy -> next = copy -> next -> next;
        }
        original = original -> next;
        copy = copy -> next;
    }
    return temp1;
}

void print(node *head)
{
    if(head == nullptr)
    {
        return;
    }
    cout << head -> data << " ";
    print(head -> next);
}

int main()
{
    node *head = takeinput();
    print(head);
    cout << endl;
    head = cloneLL(head);
    print(head);
    return 0;
}