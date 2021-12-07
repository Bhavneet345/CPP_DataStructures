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
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

int length(node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    return 1 + length(head -> next);
}

node* appendFirsttoLast(node *head, int n)
{
    int count = 0;
    node *temp1 = head, *temp2 = head, *temp3 = temp2;
    int degree = length(head) - n;
    if(degree > 0)
    {
        while(count != degree)
        {
            temp1 = temp1 -> next;
            count++;
        }
        node *last = temp1;
        while(last -> next != NULL)
        {
            last = last -> next;
        }
        count = 0;
        while(count != degree - 1)
        {
            temp2 = temp2 -> next;
            count++;
        }
        last -> next = temp3;
        temp2 -> next = NULL;
        head = temp1;
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
    print(head);
    cout << endl;
    int pos;
    cin >> pos;
    head = appendFirsttoLast(head, pos);
    print(head);
    return 0;
}