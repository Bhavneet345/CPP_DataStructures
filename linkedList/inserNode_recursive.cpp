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

node *insertNode(node *head, int pos, int data)
{
    if(head == NULL)
    {
        return head;
    }
    else if(pos == 0)
    {
        node *newnode = new node(data);
        newnode -> next = head;
        head = newnode;
    }
    node *temp = insertNode(head -> next, pos - 1, data);
    head -> next = temp;
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
    print(head);
    cout << endl;
    int data, pos;
    cin >> pos >> data;
    head = insertNode(head, pos, data);
    print(head);
}