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

node *takeInput(node *head)
{
    int data;
    cin >> data;
    node *head, *tail;
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

// worst case complexity - O(m * n)
// m - length of head1
// n - length of head2
int mergePoint(node *head1, node *head2)
{
    if(head1 -> next == NULL)
    {
        return head1 -> data;
    }
    int ans = 0;
    node *temp = head2;
    while(temp != nullptr)
    {
        if(temp -> next == head1 -> next)
        {
            ans = head1 -> next -> data;
        }
        temp = temp -> next;
    }
    if(ans == 0)
    {
        ans = mergePoint(head1 -> next, head2);
    }
    return ans;
}