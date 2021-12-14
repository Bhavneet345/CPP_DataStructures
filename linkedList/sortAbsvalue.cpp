#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
    node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

node *takeInput()
{
    int data;
    cin >> data;
    node *head = NULL, *tail = NULL;
    while(data != -1)
    {
        node *newnode = new node(data);
        if(head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail -> next = newnode;
            tail = tail -> next;
        }
        cin >> data;
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

node *sortAbs(node *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    }
    node *current = head, *prev = nullptr;
    while(current)
    {
        if(current -> data < 0 && current != head)
        {
            prev -> next = current -> next;
            current -> next = head;
            head = current;
            current = prev;
        }
        prev = current;
        current = current -> next;
    }
    return head;
}

int main()
{
    node *head = takeInput();
    print(head);
    cout << endl;
    head = sortAbs(head);
    print(head);
    return 0;
}