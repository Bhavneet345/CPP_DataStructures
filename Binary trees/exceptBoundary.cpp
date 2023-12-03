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

void leftBoundary(binaryTreeNode<int> *root, vector<int> &res)
{
    if(root == nullptr || (root -> left == nullptr && root -> right == nullptr))
    {
        return;
    }
    res.push_back(root -> data);
    if(root -> left != nullptr)
    {
        leftBoundary(root -> left, res);
    }
    else
    {
        leftBoundary(root -> right, res);
    }
    return;
}

void children(binaryTreeNode<int> *root, vector<int> &res)
{
    if(root  == nullptr)
    {
        return;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
        res.push_back(root -> data);
        return;
    }
    children(root -> left, res);
    children(root -> right, res);
}

void rightBoundary(binaryTreeNode<int> *root, vector<int> &res)
{
    if(root == nullptr || (root -> left == nullptr && root -> right == nullptr))
    {
        return;
    }
    if(root -> right != nullptr)
    {
        rightBoundary(root -> right, res);
    }
    else
    {
        rightBoundary(root -> left, res);
    }
    res.push_back(root -> data);
    return;
}

vector<int> traverseBoundary(binaryTreeNode<int>* root){
    vector<int> res;
    if(root == nullptr)
    {
        return res;
    }
    res.push_back(root -> data);
    if(root -> left == nullptr && root -> right == nullptr)
    {
        return res;
    }
    leftBoundary(root -> left, res);
    children(root, res);
    rightBoundary(root -> right, res);
    return res;
}

int sumTree(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int sum = root -> data;
    sum += sumTree(root -> left) + sumTree(root -> right);
    return sum;
}

int exceptBoundary(binaryTreeNode<int> *root) 
{
    int sum = 0, boundarysum = 0;
    vector<int> boundary = traverseBoundary(root);
    for(int i = 0; i < boundary.size(); i++)
    {
        boundarysum += boundary[i];
    }
    sum = sumTree(root);
    return sum - boundarysum;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    int res = exceptBoundary(root);
    cout << res;
    return 0;
}