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

bool searchInBST(binaryTreeNode<int> *root, int k)
{
    if(root == nullptr)
    {
        return false;
    }
    if(root -> data > k)
    {
        return searchInBST(root -> left, k);
    }
    if(root -> data < k)
    {
        return searchInBST(root -> right, k);
    }
    return true;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int data;
    cin >> data;
    if(searchInBST(root, data))
    {
        cout << "true";
    }
    else 
    {
        cout << "false";
    }
    return 0;
}