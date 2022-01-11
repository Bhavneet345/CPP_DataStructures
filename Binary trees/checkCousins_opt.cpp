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

int findParentHeight(binaryTreeNode<int> *root, int element)
{
    if(root == nullptr || root -> data == element)
    {
        return 0;
    }
    if(root -> left != nullptr)
    {
        if(root -> left -> data == element)
        {
            return 1;
        }
    }
    if(root -> right != nullptr)
    {
        if(root -> right -> data == element)
        {
            return 1;
        }
    }
    int left = findParentHeight(root -> left, element);
    int right = findParentHeight(root -> right, element);
    if(left == 0 && right == 0)
    {
        return 0;
    }
    return max(left, right) + 1;
}

bool isSiblings(binaryTreeNode<int> *root, int p, int q)
{
    if(root == nullptr)
    {
        return false;
    }
    if(root -> left != nullptr && root -> right != nullptr)
    {
        if(root -> left -> data == p && root -> right -> data == q)
        {
            return true;
        }
        if(root -> left -> data == q || root -> right -> data == p)
        {
            return true;
        }
        else
        {
            return isSiblings(root -> left, p, q) || isSiblings(root -> right, p, q);
        }
    }
    if(root -> left != nullptr)
    {
        return isSiblings(root -> left, p, q);
    }
    return isSiblings(root -> right, p, q);
}

bool isCousin(binaryTreeNode<int> *root, int p, int q)
{
    if(root == nullptr)
    {
        return false;
    }
    return(findParentHeight(root , p) == findParentHeight(root, q) && !isSiblings(root, p, q));
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    int p, q;
    cin >> p >> q;
    if(isCousin(root, p, q))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}