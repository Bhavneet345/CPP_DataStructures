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

void print(node *head)
{
    if(head == NULL)
    {
        return;
    }
    cout << head -> data << " ";
    print(head -> next);
}

node *insertNode(node *head, int pos, int data)
{
    node *newnode = new node(data);
    if(pos == 0 || head == NULL)
    {
        newnode -> next = head;
        head = newnode;
    }
    else 
    {
        int count = 0;
        node *temp = head;
        while(temp != NULL && count < pos - 1)
        {
            temp = temp -> next;
            ++count;
        }
        if(temp != NULL)
        {
            newnode -> next = temp -> next;
            temp -> next = newnode;
        }
    }
    return head;
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