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

int length(node<int> *head)
{
    if(head == nullptr)
    {
        return 0;
    }
    return 1 + length(head -> next);
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

// can also swap first and second list to check which list has greater size for space O(1)
node<int>* addTwoLists(node<int> *first, node<int> *second)
{
    if(first == nullptr)
    {
        return second;
    }
    if(second == nullptr)
    {
        return first;
    }
    first = reverse(first), second = reverse(second);
    node <int> *head1 = first, *head2 = second;
    int sum = (head1 -> data + head2 -> data), carry = sum / 10;
    node<int> *newnode = new node<int>(sum % 10), *tail = newnode;
    head1 = head1 -> next;
    head2 = head2 -> next;
    while(head1 != nullptr && head2 != nullptr)
    {
        int sum = (head1 -> data + head2 -> data) + carry;
        tail -> next = new node<int>(sum % 10);
        tail = tail -> next;
        carry = sum / 10;
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    while(head1 != nullptr)
    {
        int sum = head1 -> data + carry;
        tail -> next = new node<int>(sum % 10);
        tail = tail -> next;
        carry = sum / 10;
        head1 = head1 -> next;
    }
    while(head2 != nullptr)
    {
        int sum = head2 -> data + carry;
        tail -> next = new node<int>(sum % 10);
        tail = tail -> next;
        carry = sum / 10;
        head2 = head2 -> next;
    }
    if(carry > 0)
    {
        tail -> next = new node<int>(carry);
    }
    return reverse(newnode);
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
    node<int> *head1 = takeInput();
    node<int> *head2 = takeInput();
    head1 = addTwoLists(head1, head2);
    print(head1);
    return 0;
}