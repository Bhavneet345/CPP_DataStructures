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

node* helper(node *head, int M, int N)
{
    if(head == NULL)
    {
        return head;
    }
    node *temp1 = head, *temp2 = NULL;
    int count = 0;
    while(count < M - 1 && temp1 != NULL)
    {
        count++;
        temp1 = temp1 -> next;
    }
    if(temp1 == NULL)
    {
        return head;
    }
   temp2 = temp1 -> next;
   count = 0;
   while(count < N - 1 && temp2 != NULL)
   {
       ++count;
       temp2 = temp2 -> next;
   }
   if(temp2 == NULL)
   {
       temp1 -> next = temp2;
   }
   else
   {
       node *small = helper(temp2 -> next, M, N);
       temp1 -> next = small;
   }
   return head;
}

node *skipMdeleteN(node *head, int M, int N)
{
    if(M == 0 && N > 0)
    {
        head = NULL;
        return head;
    }
    else if(N == 0)
    {
        return head;
    }
    head = helper(head, M, N);
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

int main()
{
    node *head = takeInput();
    print(head);
    cout << endl;
    int m, n;
    cin >> m >> n;
    head = skipMdeleteN(head, m, n);
    print(head);
    return 0;    
}