#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;
// 10 20 30 40 50 -1 -1 -1 -1 -1 -1

binaryTreeNode<int>* takeinput()
{
    int data;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        binaryTreeNode<int> *front = pending.front();
        pending.pop();
        cin >> data;
        if(data != -1)
        {
            binaryTreeNode<int> *newnode = new binaryTreeNode<int>(data);
            pending.push(newnode);
            front -> left = newnode;
        }
        else
        {
            front -> left = nullptr;
        }
        cin >> data;
        if(data != -1)
        {
            binaryTreeNode<int> *newnode = new binaryTreeNode<int>(data);
            pending.push(newnode);
            front -> right = newnode;
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
    int left = height(root -> left), right = height(root -> right);
    return 1 + max(left , right);
}

int diameter(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int d = height(root -> left) + height(root -> right);
    int ld = diameter(root -> left);
    int rd = diameter(root -> right);
    return max(d, max(ld, rd));
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    cout << "diameter: " << diameter(root);
    return 0; 
}

