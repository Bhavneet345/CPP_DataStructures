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

binaryTreeNode<int> *retInorderPredecessor(binaryTreeNode<int> *root)
{
    if(root -> left == nullptr && root -> right == nullptr)
    {
        return root;
    }
    return retInorderPredecessor(root -> right);
}

binaryTreeNode<int>* deleteBST(binaryTreeNode<int> *root, int data)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    if(root -> data > data)
    {
        root -> left = deleteBST(root -> left, data);
    }
    else if(root -> data < data)
    {
        root -> right = deleteBST(root -> right, data);
    }
    else
    {
        if(root -> left == nullptr && root -> right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if(root -> right == nullptr)
        {
            binaryTreeNode<int> *temp = root;
            root = root -> left;
            delete temp;
        }
        else if(root -> left == nullptr)
        {
            binaryTreeNode<int> *temp = root;
            root = root -> right;
            delete temp;
        }
        else
        {
            binaryTreeNode<int> *tempIP = retInorderPredecessor(root -> left);
            root -> data = tempIP -> data;
            root -> left = deleteBST(root -> left, tempIP -> data);
        }
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
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    root = deleteBST(root, data);
    inOrder(root);
    cout << endl;
    preOrder(root);
    return 0;
}