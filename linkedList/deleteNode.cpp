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

int length(node *head)
{
    int count = 0;
    node *temp = head;
    while(temp != NULL)
    {
        ++count;
        temp = temp -> next;
    }
    return count;
}

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

node* deleteNode(node *head, int pos)
{
    if(head == NULL)
    {
        return head;
    }
    else if(pos == 0)
    {
        head = head -> next;
    }
    else if(length(head) > pos)
    {
        node *temp = head;
        int count = 0;
        while(temp != NULL && count < pos - 1)
        {
            temp = temp -> next;
            ++count;
        }
        if(temp != NULL)
        {
            node *a = temp -> next;
            node *b = a -> next;
            temp -> next = b;
        
        }
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
    int pos;
    cin >> pos;
    print(head);
    cout << endl;
    deleteNode(head, pos);
    print(head);
    return 0;
}