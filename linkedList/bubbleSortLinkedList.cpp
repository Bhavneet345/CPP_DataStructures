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

void print(node *head)
{
    if(head == NULL)
    {
        return;
    }
    cout << head -> data << " ";
    print(head -> next);
}

int length(node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    return 1 + length(head -> next);
}

node *bubbleSort(node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    int count = length(head);
    node *current = head, *prev = NULL;
    while(count != 1)
    {
        current = head, prev = NULL;
        while(current -> next != NULL)
        {
            if(current -> data > current -> next -> data)
            {
                node *temp = current -> next;
                current -> next = current -> next -> next;
                temp -> next = current;
                if(prev == NULL)
                {
                    head = temp;
                }
                else
                {
                    prev -> next = temp;
                }
                prev = temp;
            }
            else
            {
                prev = current;
                current = current -> next;
            }
        }
        count--;
    }
    return head;
}

int main()
{
    node *head = takeInput();
    print(head);
    cout << endl;
    head = bubbleSort(head);
    print(head);
    return 0;
}

