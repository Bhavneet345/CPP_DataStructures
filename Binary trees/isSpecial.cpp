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

bool isSpecial(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return true;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
        return true;
    }
    if(root -> left == nullptr || root -> right == nullptr)
    {
        return false;
    }
    return isSpecial(root -> left) && isSpecial(root -> right);
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    if(isSpecial(root))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}