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

node *deleteNode(node *head, int pos)
{
    if(pos < 0 || head == NULL)
    {
        return head;
    }
    else if(pos == 0)
    {
        head = head -> next;
        return head;
    }
    node *temp = deleteNode(head -> next, pos - 1);
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
    int pos;
    cin >> pos;
    head = deleteNode(head, pos);
    print(head);
}