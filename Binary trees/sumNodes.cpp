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

int sum(binaryTreeNode<int> *root)
{
    int result = 0;
    if(root == nullptr)
    {
        return result;
    }
    result = root -> data;
    result += sum(root -> left) + sum(root -> right);
    return result;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    cout << sum(root);
    return 0;
}