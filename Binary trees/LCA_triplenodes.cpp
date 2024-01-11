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

binaryTreeNode<int>* LCA(binaryTreeNode<int> *root, int node1, int node2, int node3)
{
    if(root == nullptr)
    {
        return root;
    }
    if(root -> data == node1 || root -> data == node2 || root -> data == node3)
    {
        return root;
    }
    binaryTreeNode<int> *left = LCA(root -> left, node1, node2, node3);
    binaryTreeNode<int> *right = LCA(root -> right, node1, node2, node3);
    if(left && right)
    {
        return root;
    }
    if(left)
    {
        return left;
    }
    return right;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int node1, node2, node3;
    cin >> node1 >> node2 >> node3;
    binaryTreeNode<int> *res = LCA(root, node1, node2, node3);
    cout << res -> data;
    return 0;
}