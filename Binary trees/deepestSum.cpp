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

int height(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return max(height(root -> left), height(root -> right)) + 1;
}

void helper(binaryTreeNode<int> *root, int height, int maxHeight, int &sum)
{
    if(root == nullptr)
    {
        return;
    }
    if(maxHeight == height)
    {
        sum += root -> data;
    }
    helper(root -> left, height + 1, maxHeight, sum);
    helper(root -> right, height + 1, maxHeight, sum);
}

int deepestLeavesSum(binaryTreeNode<int>*root)
{
    int sum = 0;
    int maxHeight = height(root);
    helper(root, 1, maxHeight, sum);
    return sum;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    cout << deepestLeavesSum(root);
    return 0;
}