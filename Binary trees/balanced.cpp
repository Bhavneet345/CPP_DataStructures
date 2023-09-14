#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

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
            binaryTreeNode<int> *leftchild = new binaryTreeNode<int>(data);
            front -> left = leftchild;
            pending.push(leftchild);
        }
        else
        {
            front -> left = nullptr;
        }
        cin >> data;
        if(data != -1)
        {
            binaryTreeNode<int> *rightchild = new binaryTreeNode<int>(data);
            front -> right = rightchild;
            pending.push(rightchild);
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
    int maximum = max(height(root -> left), height(root -> right));
    return maximum + 1;
}

bool isBalanced(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return true;
    }
    if(!(isBalanced(root -> left) && isBalanced(root -> right)))
    {
        return false;
    }
    int lh = 1 + height(root -> left), rh = 1 + height(root -> right);
    int bf = lh - rh;
    if(bf >= -1 && bf <= 1)
    {
        return true;
    }
    return false;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    if(isBalanced(root))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}