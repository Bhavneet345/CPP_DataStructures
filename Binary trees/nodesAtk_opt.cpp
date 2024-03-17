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

void depth(binaryTreeNode<int> *root, int distancefromroot)
{
    if(root == nullptr)
    {
        return;
    }
    if(distancefromroot == 0)
    {
        cout << root -> data << endl;
        return;
    }
    depth(root -> left, distancefromroot - 1);
    depth(root -> right, distancefromroot - 1);
    return;
}

int distanceFromroot(binaryTreeNode<int> *root, int node, int k)
{
    if(root == nullptr)
    {
        return -1;
    }
    if(root -> data == node)
    {
        depth(root, k);
        return 0;
    }
    int left = distanceFromroot(root -> left, node, k);
    if(left != -1)
    {
        if(k == left)
        {
            cout << root -> data << endl;
        }
        else if(k > left)
        {
            depth(root -> right, k - left - 2);
        }
        return left + 1;
    }
    int right = distanceFromroot(root -> right, node, k);
    if(right != -1)
    {
        if(k == right)
        {
            cout << root -> data << endl;
        }
        else if(k > right)
        {
            depth(root -> left, k - right - 2);
        }
        return right + 1;
    }
    return -1;
}