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

int height(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return max(height(root -> left), height(root -> right)) + 1;
}


pair<binaryTreeNode<int>*, bool> isBST(binaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if(root == nullptr)
    {
        pair<binaryTreeNode<int>*, bool>p;
        p.first = root;
        p.second = true;
        return p;
    }
    if(root -> data < min || root -> data > max)
    {
        pair<binaryTreeNode<int>*, bool>p;
        p.first = root;
        p.second = false;
        return p;
    }
    pair<binaryTreeNode<int>*, bool>left = isBST(root -> left, min, root -> data - 1);
    pair<binaryTreeNode<int>*, bool>right = isBST(root -> right, root -> data - 1, max);
    pair<binaryTreeNode<int>*, bool>output;
    output.first = root;
    if(left.second && right.second)
    {
        output.second = true;
    }
    else
    {
        output.second = false;
    }
    return output;
}

void helper(binaryTreeNode<int>*root, int &max)
{
    if(root == nullptr)
    {
        return;
    }
    helper(root -> left, max);
    pair<binaryTreeNode<int>*, bool>node = isBST(root);
    if(node.second)
    {
        int largest = height(node.first);
        if(max < largest)
        {
            max = largest;
        }
    }
    helper(root -> right, max);
}


int largestBSTSubtree(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int max = INT_MIN;
    helper(root, max);
    if(max != INT_MIN)
    {
        return max;
    }
    return 0;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int res = largestBSTSubtree(root);
    cout << res;
    return 0;
}