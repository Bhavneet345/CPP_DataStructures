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

node* removeDuplicates(node *head)
{
    // if(head == NULL)
    // {
    //     return head;
    // }
    // node *temp = head -> next, *newnode = head, *checknode = newnode;
    // int checkdata = head -> data;
    // while(temp != NULL)
    // {
    //     if(temp -> data != checkdata)
    //     {
    //         checkdata = temp -> data;
    //         checknode -> next = temp;
    //         checknode = checknode -> next;
    //     }
    //     temp = temp -> next;
    // }
    // checknode -> next = NULL;
    // head = newnode;
    // return head;
    node *current = head;
    while(current -> next != NULL)
    {
        if(current -> data == current -> next -> data)
        {
            current -> next = current -> next -> next;
        }
        else
        {
            current = current -> next;
        }
    }
    return head;
}

int main()
{
    node *head = takeInput();
    print(head);
    cout << endl;
    head = removeDuplicates(head);
    print(head);
    return 0;
}