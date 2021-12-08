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

node * takeInput()
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

node* merge2sorted(node *head1, node *head2)
{
    node *newnode = NULL, *tail = newnode;
    if(head1 == NULL)
    {
        return head2;
    }

    if(head2 == NULL)
    {
        return head1;
    }

    if(head1 -> data > head2 -> data)
    {
        newnode = tail = head2;
        head2 = head2 -> next;
    }
    else
    {
        newnode = tail = head1;
        head1 = head1 -> next;
    }

    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> data > head2 -> data)
        {
            tail -> next = head2;
            tail = tail -> next;
            head2 = head2 -> next;
        }
        else
        {
            tail -> next = head1;
            tail = tail -> next;
            head1 = head1 -> next;
        }
    }
    if(head1 != NULL)
    {
        tail -> next = head1;
    }
    if(head2 != NULL)
    {
       tail -> next = head2;
    }
    return newnode;
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

node *midPoint(node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    node *slow = head, *fast = head -> next;
    while(fast != NULL && fast -> next != NULL)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

node *helper(node *head, node *tail)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    node *mid = midPoint(head);
    node *temp = mid -> next;
    mid -> next = NULL;
    node *head1 = helper(head, mid);
    node *head2 = helper(temp, tail);
    head = merge2sorted(head1, head2);
    return head;
}

node* mergeSort(node *head)
{
    if(head == NULL)
    {
        return head;
    }
    node *tail = head;
    while(tail -> next != NULL)
    {
        tail = tail -> next;
    }
    head = helper(head, tail);
    return head;
}

int main()
{
    node *head = takeInput();
    head = mergeSort(head);
    print(head);
    return 0;
}