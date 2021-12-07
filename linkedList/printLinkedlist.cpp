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

node* createNode()
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
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head -> next;
    }
}

int main()
{
    node *head = createNode();
    cout << "Nodes are as follows\n";
    print(head);
    return 0;
}