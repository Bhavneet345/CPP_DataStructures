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

node* createNode(int nodes)
{
    int data;
    cin >> data;
    node *head = new node(data); 
    node *temp = head;
    for(int i = 2; i <= nodes; i++)
    {
        cin >> data;
        node *newnode = new node(data);
        temp -> next = newnode;
        temp = newnode;
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
    int nodes;
    cin >> nodes;
    node *head = createNode(nodes);
    cout << "Nodes are as follows\n";
    print(head);
    return 0;
}