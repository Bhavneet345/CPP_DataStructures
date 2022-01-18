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

vector<int>* longestPath(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    vector<int> *res = new vector<int>;
    if(root -> left == nullptr && root -> right == nullptr)
    {
        res->push_back(root -> data);
        return res;
    }
    vector<int> *left = longestPath(root -> left);
    vector<int> *right = longestPath(root -> right);
    if(left != nullptr && right != nullptr)
    {
        if(left->size() > right->size())
        {
            left->push_back(root -> data);
            return left;
        }
        right->push_back(root -> data);
        return right;
    }
    if(left == nullptr)
    {
        right->push_back(root -> data);
        return right;
    }
    if(right == nullptr)
    {
        left->push_back(root -> data);
        return left;
    }
    return nullptr;
}


int main()
{
    binaryTreeNode<int> *root = takeInput();
    cout << longestPath(root);
    return 0;
}