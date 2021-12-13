#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this -> data = data;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
};

node *takeInput()
{
    int data;
    cin >> data;
    node *head = nullptr, *tail = nullptr;
    while(data != -1)
    {
        node *newnode = new node(data);
        if(head == nullptr)
        {
            head = tail = newnode;
        }
        else
        {
            node *temp = tail;
            tail -> next = newnode;
            tail = tail -> next;
            tail -> prev = temp;
        }
        cin >> data;
    }
    return head;
}

node *insertNode(node *head, int data)
{
    node *newnode = new node(data);
    node *current = head, *previous = nullptr;
    while(current != NULL)
    {
        if(current -> data > newnode -> data)
        {
            break;
        }
        previous = current;
        current = current -> next;
    }
    if(previous != nullptr && current != nullptr)
    {
        newnode -> next = current;
        newnode -> prev = previous;
        previous -> next = newnode;
        current -> prev = newnode;
    }
    else if(current == nullptr)
    {
        newnode -> prev = previous;
        newnode -> next = nullptr;
        previous -> next = newnode;
    }
    else
    {
        newnode -> next = current;
        newnode -> prev = previous;
        current -> prev = newnode;
        head = newnode;
    }
    return head;
}

void print(node *head)
{
    if(head == NULL)
    {
        return;
    }
    cout << head -> data << " ";
    print(head -> next);
}

int main()
{
    node *head = takeInput();
    int data;
    cin >> data;
    print(head);
    cout << endl;
    head = insertNode(head, data);
    print(head);
    return 0;
}