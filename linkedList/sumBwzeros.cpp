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
    node *head, *tail;
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

node *addBwzeros(node *head)
{
    int sum = 0;
    node *newnode = nullptr;
    head = head -> next;
    while(head -> data != 0)
    {
        sum += head -> data;
        head = head -> next;
    }
    newnode = new node(sum);
    newnode -> next = addBwzeros(head);
    return newnode;
}