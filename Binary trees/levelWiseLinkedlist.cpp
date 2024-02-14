#include<iostream>
#include<queue>
#include<vector>
#include "binaryTreeNode.h"
using namespace std;
template<typename type>

class Node
{
    public:
    type data;
    Node<type> *next;
    Node(type data)
    {
        this -> data = data;
        this -> next = nullptr;
    }
};

binaryTreeNode<int>* takeInput()
{
    int data;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data), *front;
    queue<binaryTreeNode<int>*>pending;
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

vector<Node<int>*> constructLinkedListForEachLevel(binaryTreeNode<int> *root)
{
    vector<Node<int>*>headers;
    if(root == nullptr)
    {
        headers.push_back(nullptr);
        return headers;
    }
    binaryTreeNode<int> *front, *temproot = root;
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    pending.push(nullptr);
    Node<int> *head = new Node<int>(root -> data);
    headers.push_back(head);
    Node<int> *temphead, *temptail;
    while(!pending.empty())
    {
        front = pending.front();
        pending.pop();
        if(front == nullptr)
        {
            if(pending.empty())
            {
                break;
            }   
            temproot = pending.front();
            temphead = new Node<int>(temproot -> data);
            temptail = temphead;
            headers.push_back(temphead);
            pending.push(nullptr);
        }
        else
        {
            if(front != temproot)
            {
                temptail -> next = new Node<int>(front -> data);
                temptail = temptail -> next;
            }
            if(front -> left != nullptr)
            {
                pending.push(front -> left);
            }
            if(front -> right != nullptr)
            {
                pending.push(front -> right);
            }
        }
    }
    return headers;
}

void printLinkedlist(vector<Node<int>*> headers)
{
    if(headers[0] == nullptr)
    {
        return;
    }
    for(int i = 0; i < headers.size(); i++)
    {
        Node<int> *head = headers[i];
        while(head)
        {
            cout << head -> data << " ";
            head = head -> next;
        }
        cout << endl;
    }
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    vector<Node<int>*> headers = constructLinkedListForEachLevel(root);
    printLinkedlist(headers);
    return 0;
}