#include<iostream>
#include<vector>
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

node* takeinput()
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

node *reverse(node *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    }
    node *small = reverse(head -> next);
    head -> next -> next = head;
    head -> next = nullptr;
    return small;
}
node *lastAppearance(node *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return head;
    }
    node *dummy = new node(-1);
    dummy -> next = head;
    node *current = dummy;
    while(current -> next != nullptr)
    {
        node *temp = current -> next -> next;
        while(temp != nullptr)
        {
            if(temp -> data == current -> next -> data)
            {
                node *duplicate = current -> next;
                current -> next = current -> next -> next;
                delete duplicate;
                break;
            }
            temp = temp -> next;
        }
        if(temp == nullptr)
        {
            current = current -> next;
        }
    }
    return dummy -> next;
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
    node *head = takeinput();
    print(head);
    cout << endl;
    head = lastAppearance(head);
    print(head);
    return 0;
}