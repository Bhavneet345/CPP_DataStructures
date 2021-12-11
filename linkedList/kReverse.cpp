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

node* takeInput()
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

node* reverse(node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }
    node *small = reverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return small;
}

node *kReverse(node *head, int k)
{
//     if(k <= 1)
//     {
//         return head;
//     }
//     node *current = head, *prev = head, *newnode = NULL;
//     int pos = 1;
//     while(prev != NULL)
//     {
//         if(pos == k || prev -> next == NULL)
//         {
//             current = prev -> next;
//             prev -> next = NULL;
//             if(newnode == NULL)
//             {
//                 newnode = reverse(head);
//             }
//             else
//             {
//                 node *temp = newnode;
//                 while(temp -> next != NULL)
//                 {
//                     temp = temp -> next;
//                 }
//                 temp -> next = reverse(head);
//             }
//             head = prev = current;
//             pos = 1;
//         }
//         if(prev != NULL && prev -> next != NULL)
//         {
//             prev = prev -> next;
//         }
//         ++pos;
//     }
//     return newnode; 
    if(k == 1 || k == 0)
    {
        return head;
    }
    node *current = head, *prev = NULL, *fwd = NULL;
    int pos = 0;
    while(pos < k && current != NULL)
    {
        fwd = current -> next;
        current -> next = prev;
        prev = current;
        current = fwd;
        pos++;
    }
    if(current != NULL)
    {
        head -> next = kReverse(current, k);
    }
    return prev;
}

int main()
{
    node *head = takeInput();
    int k;
    cin >> k;
    print(head);
    cout << endl;
    head = kReverse(head, k);
    print(head);
    return 0;
}


