#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* takeinput()
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

void printNodesWithoutSibling(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    if(root -> right == nullptr && root -> left != nullptr)
    {
        cout << root -> left -> data << " "; 
    }
    else if(root -> left == nullptr && root -> right != nullptr)
    {
        cout << root -> right -> data << " ";
    }
    printNodesWithoutSibling(root -> left);
    printNodesWithoutSibling(root -> right);
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    printNodesWithoutSibling(root);
    return 0;
}