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

binaryTreeNode<int>* removeleaf(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return root;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
        root = nullptr;
        return root;
    }
    root -> left = removeleaf(root -> left);
    root -> right = removeleaf(root -> right);
    return root;
}

void print(binaryTreeNode<int> *root)
{
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        binaryTreeNode<int> *front = pending.front();
        pending.pop();
        cout << front -> data << ":";
        if(front -> left != nullptr)
        {
            cout << front -> left -> data << ",";
            pending.push(front -> left);
        }
        if(front -> right != nullptr)
        {
            cout << front -> right -> data;
            pending.push(front -> right);
        }
        cout << endl;
    }
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    print(root);
    root = removeleaf(root);
    cout << endl;
    print(root);
    return 0;
}