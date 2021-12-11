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

node* swapNodes(node *head, int i, int j)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    if(i == j)
    {
        return head;
    }
    node *temp1 = NULL, *temp2 = NULL, *current = head, *first = head, *second = head;
    int count = 0;
    while(current != NULL)
    {
        if(count == i - 1)
        {
            temp1 = current;
            first = temp1 -> next;
        }
        else if(count == j - 1)
        {
            temp2 = current;
            second = temp2 -> next;
        }
        current = current -> next;
        ++count;
    }
    if(temp1 != NULL)
    {
        temp1 -> next = second;
    }
    else
    {
        head = second;
    }
    if(temp2 != NULL)
    {
        temp2 -> next = first;
    }
    else
    {
        head = first;
    }
    node *store = second -> next;
    second -> next = first -> next;
    first -> next = store;
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
    int i, j;
    cin >> i >> j;
    print(head);
    cout << endl;
    head = swapNodes(head, i, j);
    print(head);
    return 0;
}