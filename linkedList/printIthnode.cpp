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

void displayIth(node *head, int i)
{
    if(head == NULL)
    {
        return;
    }
    if(i == 0)
    {
        cout << head -> data;
    }
    displayIth(head -> next, i - 1);
}

int main()
{
    node *head = takeInput();
    int pos;
    cin >> pos;
    displayIth(head, pos);
    return 0;
}