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

int main()
{
    node *head = takeInput();
    int len = length(head);
    cout << len;
    return 0;
}