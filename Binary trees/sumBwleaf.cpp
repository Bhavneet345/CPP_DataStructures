#include<iostream>
#include<queue>
#include "binaryTreeNode.h"

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

int returnMaxSumpath(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int leftmaxSum = returnMaxSumpath(root -> left);
    int rightmaxSum = returnMaxSumpath(root -> right);
    int ans = root -> data + max(leftmaxSum, rightmaxSum);
    return ans;
}

int maxleafpath(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int leftmax = returnMaxSumpath(root -> left);
    int rightmax = returnMaxSumpath(root -> right);
    if(root -> left != nullptr && root -> right != nullptr)
    {
        int maxpathfromroot = root -> data + leftmax + rightmax;
        return max(maxpathfromroot, max(maxleafpath(root -> left), maxleafpath(root -> right)));
    }
    if(root -> left != nullptr)
    {
        return maxleafpath(root -> left);
    }
    else if(root -> right != nullptr)
    {
        return maxleafpath(root -> right);
    }
    return -1;
}

int findMaxSumPath(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return maxleafpath(root);
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    cout << findMaxSumPath(root);
    return 0;
}