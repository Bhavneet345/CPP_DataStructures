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

bool isPalindrome(node *head)
{
    bool Palindrome = false;
    if(head == NULL)
    {
        return true;
    }
    else
    {
        node *a = head, *b = head -> next;
        while(b -> next != NULL)
        {
            a = a -> next;
            b = a ->next;
        }
        if(head -> data == b -> data)
        {
            a -> next = NULL;
            Palindrome = isPalindrome(head -> next);
        }
    }
    return Palindrome;
}

int main()
{
    node *head = takeInput();
    if(isPalindrome(head))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}