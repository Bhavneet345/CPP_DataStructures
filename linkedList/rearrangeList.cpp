#include<iostream>
using namespace std;
template<typename type>

class node
{
    public:
    type data;
    node <type> *next;
    node(type data)
    {
        this -> data = data;
        this -> next = nullptr;
    }
};

node<int>* takeInput()
{
    int data;
    cin >> data;
    node <int> *head = nullptr, *tail = nullptr;
    while(data != -1)
    {
        if(head == nullptr)
        {
            head = tail = new node<int>(data);
        }
        else
        {
            tail -> next = new node<int>(data);
            tail = tail -> next;
        }
        cin >> data;
    }
    return head;
}

node<int>* reverse(node<int> *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    }
    node<int> *small = reverse(head -> next);
    head -> next -> next = head;
    head -> next = nullptr;
    return small;
}

int length(node<int> *head)
{
    if(head == nullptr)
    {
        return 0;
    }
    return 1 + length(head -> next);
}

node<int> *midpoint(node<int> *head)
{
    node<int> *fast = head, *slow = head;
    if(length(head) % 2 == 0)
    {
        fast = head -> next;   
    }
    while(fast != nullptr && fast -> next != nullptr)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

node<int>* reArrangelist(node<int> *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    } 
    node<int> *mid = midpoint(head);
    node<int> *newnode = mid -> next;
    mid -> next = nullptr;
    newnode = reverse(newnode);
    node<int> *current = head, *newcurrent = newnode, *fwd = current -> next, *newfwd = newcurrent -> next;
    current -> next = newcurrent;
    while(fwd != nullptr && newfwd != nullptr)
    {
        node<int> *temp = fwd -> next, *newtemp = newfwd -> next;
        newcurrent -> next = fwd;
        fwd -> next = newfwd;
        fwd = temp;
        newcurrent = newfwd;
        newfwd = newtemp;
    }
    if(newfwd == nullptr)
    {
        newcurrent -> next = fwd;
    }
    return head;
}

void print(node<int> *head)
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
    node<int> *head = takeInput();
    print(head);
    cout << endl;
    head = reArrangelist(head);
    print(head);
    return 0;
}