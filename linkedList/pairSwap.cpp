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

node<int>* pairSwap(node<int> *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    }
    node<int> *temp = head -> next;
    head -> next = head -> next -> next;
    temp -> next = head;
    temp -> next -> next = pairSwap(head -> next);
    head = temp;
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
    head = pairSwap(head);
    print(head);
    return 0;
}