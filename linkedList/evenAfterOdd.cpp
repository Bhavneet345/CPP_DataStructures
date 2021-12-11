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

node* evenAfterOdd(node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    node *even = NULL, *temp1 = even, *odd = NULL, *temp2 = odd;
    while(head != NULL)
    {
        if(head -> data % 2 == 0)
        {
            if(even == NULL)
            {
                even = temp1 = head;
            }
            else
            {
                temp1 -> next = head;
                if(temp1 -> next != NULL)
                {
                    temp1 = temp1 -> next;
                }
            }
        }
        else
        {
            if(odd == NULL)
            {
                odd = temp2 = head;
            }
            else
            {
                temp2 -> next = head;
                if(temp2 -> next != NULL)
                {
                    temp2 = temp2 -> next;
                }
            }
        }
        head = head -> next;
    }
    if(odd == NULL && even != NULL)
    {
        temp1 -> next = NULL;
        return even;
    }
    else if(even == NULL && odd != NULL)
    {
        temp2 -> next = NULL;
        return odd;
    }
    else
    {
        temp1 -> next = NULL;
        temp2 -> next = even;
        return odd;
    }
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
    head = evenAfterOdd(head);
    print(head);
    return 0;    
}