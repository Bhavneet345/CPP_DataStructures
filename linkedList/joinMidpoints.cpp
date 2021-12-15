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
    node *midpoints = nullptr, *prev = nullptr, *temp1 = head, *temp2 = head -> next;
    float midx, midy;
    while(temp2 != nullptr)
    {
        if(temp2 -> x == temp1 -> x || temp2 -> y == temp1 -> y)
        {
            prev = temp2;
            temp2 = temp2 -> next;
        }
        else
        {
            break;
        }
    }
    midx = (prev -> x + temp1 -> x) / 2;
    midy = (prev -> y + temp1 -> y) / 2;
    midpoints = new node(floorf(midx), floorf(midy));
    midpoints -> next = connectMidpoints(prev);
    return midpoints;
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