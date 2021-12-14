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

bool findCyclenode(node **head, node *newnode)
{
    bool isCycle = false;
    if((*head) == nullptr)
    {
        if(newnode -> next == newnode)
        {
            isCycle = true;
        }
        newnode -> next = nullptr;
        (*head) = newnode;
    }
    else
    {
        node *temp = (*head), *prev = nullptr;
        while(temp != nullptr)
        {
            if(newnode -> next == temp)
            {
                isCycle = true;
            }
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = newnode;
        newnode -> next = nullptr;
    }
    return isCycle;
}

node* checkRemovecycle(node *head)
{
    bool cycle = false;
    node *fast = head, *slow = head, *newnode = head;
    while(fast != nullptr && fast -> next != nullptr)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow)
        {
            cycle = true;
            break;
        }
    }
    if(cycle)
    {
        newnode = nullptr;
        node *temp = head, *current = temp -> next, *fwd = current;
        bool removed = findCyclenode(&newnode, temp); 
        while(!removed)
        {
            fwd = current -> next;
            removed = findCyclenode(&newnode, current);
            current = fwd;
        }
    }
    return newnode;
}

int main()
{
    node *head = takeInput(), *temp = head;
    while(temp -> next != nullptr)
    {
        temp = temp -> next;
    }
    temp -> next = head -> next;
    head = checkRemovecycle(head);
    print(head);
    return 0;
}
