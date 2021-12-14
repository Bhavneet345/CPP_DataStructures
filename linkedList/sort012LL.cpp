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

node *insertNode(node **head, node **tail, node *newnode)
{
    if((*head) == nullptr)
    {
        (*head) = (*tail) = newnode;
    }
    else
    {
        (*tail) -> next = newnode;
        (*tail) = (*tail) -> next;
    }
    return *head;
}

node *sort012(node *head)
{
    node *sorted = nullptr, *tail = nullptr;
    int count[3] = {0};
    while(head)
    {
        count[head -> data] += 1;
        head = head -> next;
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            node *newnode = new node(i);
            insertNode(&sorted, &tail, newnode);
        }
    }
    return sorted;
}

int main()
{
    node *head = takeInput();
    print(head);
    cout << endl;
    head = sort012(head);
    print(head);
    return 0;
}