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
        this -> next = nullptr;
    }
};

Node* takeinput()
{
    int data;
    cin >> data;
    Node *head = nullptr, *tail = nullptr;
    while(data != -1)
    {
        if(head == nullptr)
        {
            head = tail = new Node(data);
        }
        else
        {
            tail -> next = new Node(data);
            tail = tail -> next;
        }
        cin >> data;
    }
    return head;
}

Node* getTail(Node *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    }
    while(head -> next != nullptr)
    {
        head = head -> next;
    }
    return head;
}

Node* Partition(Node *head, Node *tail, Node **newhead, Node **newtail)
{     
    Node *pivot = tail, *current = head, *prev = nullptr;
    int pivotdata = pivot -> data;
    while(current != pivot)
    {
        if(current -> data < pivotdata)
        {
            if((*newhead) == nullptr)
            {
                (*newhead) = current;
            }
            prev = current;
            current = current -> next;
        }
        else
        {
            if(prev != nullptr)
            {
                prev -> next = current -> next;
            }
            Node *temp = current -> next;
            tail -> next = current;
            current -> next = nullptr;
            tail = current;
            current = temp;
        }
    }
    if((*newhead) == nullptr)
    {
        (*newhead) = pivot;
    }
    (*newtail) = tail;
    return pivot;
}

Node *quickSorthelper(Node *head, Node *tail)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    }
    Node *pivot, *newhead = nullptr, *newtail = nullptr;
    pivot = Partition(head, tail, &newhead, &newtail); 
    Node *temp = newhead, *small, *large;
    //normal case
    if(pivot != newhead)
    {
        while(temp -> next != pivot)
        {
            temp = temp -> next;
        }
       small = newhead;
       large = pivot -> next;
       temp -> next = nullptr;
       small = quickSorthelper(small, temp);
       tail = getTail(small);
       tail -> next = pivot;
       pivot -> next = quickSorthelper(large, newtail);
       head = small;
    }
    //newhead = pivot
    else
    {
        large = pivot -> next;
        pivot -> next = quickSorthelper(large, newtail);
        head = pivot;
    }
    return head;
}

Node* quickSortLL(Node *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    }
    Node *tail = getTail(head);
    head = quickSorthelper(head, tail);
    return head;
}


void print(Node *head)
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
    Node *head = takeinput();
    print(head);
    cout << endl;
    Node *newhead = nullptr, *newtail = nullptr;
    // head = Partition(head, getTail(head), &newhead, &newtail);
    head = quickSortLL(head);
    print(head);
    // print(newhead);
    return 0;
}