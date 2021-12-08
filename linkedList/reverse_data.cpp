#include<iostream>
using namespace std;


class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1)
    {
        Node *newnode = new Node(data);
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

int length(Node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    return 1 + length(head -> next);
}

Node *helper(Node *head, int length)
{
    if(length <= 0)
    {
        return head;
    }
    Node *temp1 = head;
    temp1 = helper(temp1 -> next, length - 2);
    Node *temp2 = head;
    int count = 0;
    while(count != length)
    {
        ++count;
        temp2 = temp2 -> next;
    }
    int swap = head -> data;
    head -> data = temp2 -> data;
    temp2 -> data = swap;
    return head;
}

Node *reverseLinkedListRec(Node *head)
{
    int len = length(head);
    head = helper(head, len - 1);
    return head;
}

void print(Node *head)
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
    Node *head = takeInput();
    print(head);
    cout << endl;
    head = reverseLinkedListRec(head);
    print(head);
    return 0;
}