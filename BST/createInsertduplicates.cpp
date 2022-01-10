#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* takeInput()
{
    int data;
    cin >> data;
    queue<binaryTreeNode<int>*>pending;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data), *front;
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

void inOrder(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void insertDuplicateNode(binaryTreeNode<int> **root)
{
    if((*root) == nullptr)
    {
        return;
    }
    binaryTreeNode<int> *temp = (*root) -> left;
    (*root) -> left = new binaryTreeNode<int>((*root) -> data);
    (*root) -> left -> left = temp;
    insertDuplicateNode(&(*root) -> left -> left);
    insertDuplicateNode(&(*root) -> right);
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    inOrder(root);
    cout << endl;
    insertDuplicateNode(&root);
    inOrder(root);
    return 0;
}