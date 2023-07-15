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

binaryTreeNode<int>* insertBST(binaryTreeNode<int> *root, int data)
{
    if(root == nullptr)
    {
        root = new binaryTreeNode<int>(data);
        return root;
    }
    if (root -> data > data)
    {
        root -> left = insertBST(root -> left, data);
    }
    else if(root -> data < data)
    {
        root -> right = insertBST(root -> right, data);
    }
    return root;
    
}

void inOrder(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
    return;
}

void preOrder(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int data;
    cin >> data;
    root = insertBST(root, data);
    inOrder(root);
    cout << endl;
    preOrder(root);
    return 0;
}