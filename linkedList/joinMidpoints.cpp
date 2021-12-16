#include<iostream>
#include<cmath>
using namespace std;

class node
{
    public:
    int x, y;
    node *next;
    node(int x, int y)
    {
        this -> x = x;
        this -> y = y;
        this -> next = nullptr;
    }
};

node *takeInput()
{
    int x, y;
    cin >> x >> y;
    node *head = nullptr, *tail = nullptr;
    while(x >= 0 && y >= 0)
    {
        node *newnode = new node(x, y);
        if(head == nullptr)
        {
            head = tail = newnode;
        }
        else
        {
            tail -> next = newnode;
            tail = tail -> next;
        }
        cin >> x >> y;
    }
    return head;
}

node *connectMidpoints(node *head)
{
    if(head == nullptr || head -> next == nullptr)
    {
        return nullptr;
    }
    node *midpoint = nullptr;
    node *temp = head;
    if(temp -> x == temp -> next -> x)
    {
        while(temp -> next != nullptr && temp -> x == temp -> next -> x)
        {
            temp = temp -> next;
        }
        midpoint = new node(temp -> x, (temp -> y + head -> y) / 2);
    }
    else if(temp -> y == temp -> next -> y)
    {
        while(temp -> next != nullptr && temp -> y == temp -> next -> y)
        {
            temp = temp -> next;
        }
        midpoint = new node((temp -> x + head -> x) / 2, temp -> y);
    }
    midpoint -> next = connectMidpoints(temp);
    return midpoint;
}

void print(node *head)
{
    if(head == nullptr)
    {
        return;
    }
    cout << head -> x << " " << head -> y << " ";
    print(head -> next);
}

int main()
{
    node *head = takeInput();
    print(head);
    cout << endl;
    head = connectMidpoints(head);
    print(head);
    return 0;
}
