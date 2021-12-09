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

node* reverse(node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    node *small = reverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return small;
}

int main()
{
    node *head = takeInput();
    print(head);
    cout << endl;
    head = reverse(head);
    print(head);
    return 0;
}