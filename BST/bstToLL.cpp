#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;
template<typename type>

class node
{
    public:
    type data;
    node<type> *next;
    node(type data)
    {
        this -> data = data;
        this -> next = nullptr;
    }
};


binaryTreeNode<int>* takeInput()
{
    int data;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*>pending;
    binaryTreeNode<int> *front;
    pending.push(root);
    while(!pending.empty())
    {
        front = pending.front();
        pending.pop();
        cin >> data;
        if(data != -1)
        {
            front -> left = new binaryTreeNode<int>(data);
            pending.push(front -> left);
        }
        else
        {
            front -> left = nullptr;
        }
        cin >> data;
        if(data != -1)
        {
            front -> right = new binaryTreeNode<int>(data);
            pending.push(front -> right);
        }
        else
        {
            front -> right = nullptr;
        }
    }
    return root;
}

pair<node<int>*, node<int>* >helper(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        pair<node<int>*, node<int>* >p;
        p.first = nullptr;
        p.second = nullptr;
        return p;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
        pair<node<int>*, node<int>* >p;
        p.first = new node<int>(root -> data);
        p.second = p.first;
        return p;
    }
    node<int> *newnode = new node<int>(root -> data);
    pair<node<int>*, node<int>* >left = helper(root -> left);
    if(left.first != nullptr)
    {
        left.second -> next = newnode;
    }
    else
    {
        left.first = left.second = newnode;
    }
    pair<node<int>*, node<int>* >right = helper(root -> right);
    if(right.first != nullptr)
    {
        newnode -> next = right.first;
    }
    else
    {
        right.first = right.second = newnode;
    }
    pair<node<int>*, node<int>* >output;
    output.first = left.first;
    output.second = right.second;
    return output;
}

node<int> *constructLinkedList(binaryTreeNode<int> *root)
{
    pair<node<int>*, node<int>* >output = helper(root);
    return output.first;
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
    binaryTreeNode<int> *root = takeInput();
    node<int> *head = constructLinkedList(root);
    print(head);
    return 0;
}