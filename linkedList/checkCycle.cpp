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

node* takeInput()
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

bool has_Cycle(node *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return 0;
    }
    node *fast = head, *slow = head;
    while(fast != nullptr && fast -> next != nullptr)
    {
        if(fast == slow)
        {
            return 1;
        }
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return 0;
}