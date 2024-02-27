#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* takeInput()
{
    int data, leftdata, rightdata;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        binaryTreeNode<int> *front = pending.front();
        pending.pop();
        cout << "Enter left child of " << front -> data << endl;
        cin >> leftdata;
        if(leftdata != -1)
        {
            front -> left = new binaryTreeNode<int>(leftdata);
            pending.push(front -> left);
        }
        else
        {
            front -> left = nullptr;
        }
        cout << "Enter right child of " << front -> data << endl;
        cin >> rightdata;
        if(rightdata != -1)
        {
            front -> right = new binaryTreeNode<int>(rightdata);
            pending.push(front -> right);
        }
        else
        {
            front -> right = nullptr;   
        }
    }
    return root;
}

bool findNode(binaryTreeNode<int> *root, int x)
{
    if(root == nullptr)
    {
        return false;
    }
    if(root -> data == x)
    {
        return true;
    }
    return findNode(root -> left, x) || findNode(root -> right, x);
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    if(findNode(root, x))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}