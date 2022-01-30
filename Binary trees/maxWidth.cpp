#include<iostream>
#include<queue>
#include<vector>
#include "binaryTreeNode.h"

binaryTreeNode<int>* takeInput()
{
    int data;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    if(data == -1)
    {
        return nullptr;
    }
    queue<binaryTreeNode<int>*> pending;
    pending.push(root);
    while(!pending.empty())
    {
        int size = pending.size();
        while(size--)
        {
            binaryTreeNode<int> *front = pending.front();
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
    }
    return root;
}

void horizontalDistance(binaryTreeNode<int> *root, int &leftwidth, int &rightwidth, int distance)
{
    if(root == nullptr)
    {
        return;
    }
    if(root -> left != nullptr)
    {
        horizontalDistance(root -> left, leftwidth, rightwidth, distance - 1);
    }
    leftwidth = min(leftwidth, distance);
    if(root -> right != nullptr)
    {
        horizontalDistance(root -> right, leftwidth, rightwidth, distance + 1);
    }
    rightwidth = max(rightwidth, distance);
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int leftwidth = 0, rightwidth = 0;
    horizontalDistance(root, leftwidth, rightwidth, 0);
    cout << leftwidth << " " << rightwidth;
    return 0;
}