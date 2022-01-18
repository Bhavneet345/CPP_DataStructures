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

bool helper(binaryTreeNode<int> *root1, binaryTreeNode<int> *root2)
{
    if(root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if(root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    if(root1 -> data != root2 -> data)
    {
        return false;
    }
    return helper(root1 -> left, root2 -> right) && helper(root1 -> right, root2 -> left);
}

bool isSymmetric(binaryTreeNode<int> *root)
{
    return helper(root, root);
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    if(isSymmetric(root))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    return 0;
}