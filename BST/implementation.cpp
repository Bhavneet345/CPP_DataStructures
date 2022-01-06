#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

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
        }
        else
        {
            front -> left = nullptr;
        }
        cin >> data;
        if(data != -1)
        {
            front -> right = new binaryTreeNode<int>(data);
        }
        else
        {
            front -> right = nullptr;
        }
    }
    return root;
}

void printlevelwise(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    queue<binaryTreeNode<int>*>pending;
    binaryTreeNode<int> *front;
    pending.push(root);
    while(!pending.empty())
    {
        front = pending.front();
        pending.pop();
        cout << front -> data << " ";
        if(front -> left != nullptr)
        {
            pending.push(front -> left);
        }
        if(front -> right != nullptr)
        {
            pending.push(front -> right);
        }
    }
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    printlevelwise(root);
    return 0;
}