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
        this -> next = nullptr;
    }
};

node *takeInout()
{
    int data;
    cin >> data;
    node *head = nullptr, *tail = nullptr;
    while(data != -1)
    {
        if(head == nullptr)
        {
            head = tail = new node(data);
        }
        else
        {
            tail -> next = new node(data);
            tail = tail -> next;
        }
        cin >> data;
    }
    return head;
}

node* checkRemovecycle(node *head)
{
    if(head -> next == nullptr)
    {
        return head;
    }
    node *fast = head -> next, *slow = head -> next;
    while(fast != slow)
    {
        if(fast == nullptr || fast -> next == nullptr)
        {
            return head;
        }
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    fast = head;
    while(fast != slow)
    {
        fast = fast -> next;
        slow = slow -> next;
    }
    while(fast -> next != slow)
    {
        fast = fast -> next;
    }
    fast -> next = nullptr;
    return head;
}

void print(node *head)
{
    if(head == nullptr)
    {
        return;
    }
    cout << head -> data << " ";
    print(head -> next);
}

int main()
{
    node *head = takeInout();
    node *temp = head;
    while(temp -> next != nullptr)
    {
        temp = temp -> next;
    }
    temp -> next = head;
    head = checkRemovecycle(head);
    print(head);
    return 0;
}

