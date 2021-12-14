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

node* deleteMid(node *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        delete head;
        return nullptr;
    }
    node *fast = head -> next, *slow = head, *prev = nullptr;
    while(fast != nullptr && fast -> next != nullptr)
    {
        fast = fast -> next -> next;
        prev = slow;
        slow = slow -> next;
    }
    if(prev == nullptr)
    {
        head = head -> next;
    }
    else
    {
        prev -> next = slow -> next;
    }
    slow -> next = nullptr;
    delete slow;
    return head;
}

int main()
{
    node *head = takeInput();
    print(head);
    cout << endl;
    head = deleteMid(head);
    print(head);
    return 0;
}