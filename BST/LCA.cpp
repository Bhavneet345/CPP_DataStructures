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

int getLCA(binaryTreeNode<int> *root, int a, int b)
{
    if(root == nullptr)
    {
        return -1;
    }   
    if(root -> data == a || root -> data == b)
    {
        return root -> data;
    }
    int left = getLCA(root -> left, a, b);
    int right = getLCA(root -> right, a, b);
    if(left != -1 && right != -1)
    {
        return root -> data;
    }
    if(left != -1)
    {
        return left;
    }
    return right;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int a, b;
    cin >> a >> b;
    int res = getLCA(root, a, b);
    cout << res;
    return 0;
}