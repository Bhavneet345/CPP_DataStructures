#include<iostream>
#include<queue>
#include<cmath>
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

void printLevelWise(binaryTreeNode<int> *root)
{
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    binaryTreeNode<int> *temp = nullptr;
    pending.push(temp);
    while(!pending.empty())
    {
        binaryTreeNode<int> *front = pending.front();
        pending.pop();
        if(front == nullptr)
        {
            if(pending.empty())
            {
                break;
            }
            pending.push(nullptr);
            cout << endl;
        }
        else
        {
            cout << front -> data << " ";
            if(front -> left != nullptr)
            {
                pending.push(front -> left);
            }
            if(front -> right != nullptr)
            {
                pending.push(front -> right);
            }
        }   
    }
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    printLevelWise(root);
    return 0;
}