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

class Pair
{
    public:
    node *head, *tail;
};

Pair helper(node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair small = helper(head -> next);
    small.tail -> next = head;
    head -> next = NULL;
    Pair ans;
    ans.head = small.head;
    ans.tail = head;
    return ans;
}

node* reverse(node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    return helper(head).head;
}

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

int main()
{
    node *head = takeInput();
    print(head);
    head = reverse(head);
    cout << endl;
    print(head);
    return 0;
}