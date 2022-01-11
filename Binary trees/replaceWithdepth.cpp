#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* takeinput()
{
    int data;
    cin >> data;
    if(data == -1)
    {
        return nullptr;
    }
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

void printLevelwise(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        int size = pending.size();
        while(size--)
        {
            cout << pending.front() -> data << " ";
            if(pending.front() -> left != nullptr)
            {
                pending.push(pending.front() -> left);
            }
            if(pending.front() -> right != nullptr)
            {
                pending.push(pending.front() -> right);
            }
            pending.pop();
        }
        cout << endl;
    }
    return;
}

void helper(binaryTreeNode<int> *root, int depth)
{
    if(root == nullptr)
    {
        return;
    }
    root -> data = depth;
    helper(root -> left, depth + 1);
    helper(root -> right, depth + 1);
}

binaryTreeNode<int> *changeToDepthTree(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    helper(root, 0);
    return root;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    printLevelwise(root);
    root = changeToDepthTree(root);
    printLevelwise(root);
    return 0;
}