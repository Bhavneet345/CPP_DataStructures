#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this -> next = nullptr;
        this -> data = data;
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

int length(Node *head)
{
    if(head == nullptr)
    {
        return 0;
    }
    return 1 + length(head -> next);
}

Node* getmid(Node *head, int &elementinleft)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    }
    Node *fast = head, *slow = head;
    elementinleft = 1;
    if(length(head) % 2 == 0)
    {
        fast = fast -> next;
    }
    while(fast  != nullptr && fast -> next  != nullptr)
    {
        ++elementinleft;
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}

Node *merge2list(Node *left, Node *right, int elementinleft, long long int &inversions)
{
    if(right == nullptr)
    {
        return left;
    }
    if(left == nullptr)
    {
        return right;
    }
    Node *dummy = new Node(-1), *tail = dummy;
    int leftpassed = 0;
    while(left != nullptr && right != nullptr)
    {
        if(left -> data <= right -> data)
        {
            ++leftpassed;
            tail -> next = left;
            tail = left;
            left = left -> next;
        }
        else
        {
            inversions += elementinleft - leftpassed;
            tail -> next = right;
            tail = right;
            right = right -> next;
        }
    }
    if(left != nullptr)
    {
        tail -> next = left;
    }
    if(right != nullptr)
    {
        tail -> next = right;
    }
    tail = dummy -> next;
    dummy -> next = nullptr;
    delete dummy;
    return tail;
}

Node* mergeSort(Node *head, long long int &inversions)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    }
    int elementinleft = 0;
    Node *mid = getmid(head, elementinleft);
    Node *newNode = mid -> next;
    mid -> next = nullptr;
    Node *left = mergeSort(head, inversions);
    Node *right = mergeSort(newNode, inversions);
    head = merge2list(left, right, elementinleft, inversions);
    return head;
}

long long int countInversion(Node *head)
{
    long long int inversion = 0;
    head = mergeSort(head, inversion);
    return inversion;
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
    long long int inversion = countInversion(head);
    cout << inversion;
    return 0;
}
