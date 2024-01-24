#include<iostream>
#include<queue>
#include<stack>
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

void printZigZag(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    bool flag = true;
    binaryTreeNode<int> *top;
    stack<binaryTreeNode<int>*>s1;
    stack<binaryTreeNode<int>*>s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty())
    {
        if(flag)
        {
            top = s1.top();
            s1.pop();
            cout << top -> data << " ";
            if(top -> left != nullptr)
            {
                s2.push(top -> left);
            }
            if(top -> right != nullptr)
            {
                s2.push(top -> right);
            }
            if(s1.empty())
            {
                cout << endl;
                flag = false;
            }
        }
        else
        {
            top = s2.top();
            s2.pop();
            cout << top -> data << " ";
            if(top -> right != nullptr)
            {
                s1.push(top -> right);
            }
            if(top -> left != nullptr)
            {
                s1.push(top -> left);
            }
            if(s2.empty())
            {
                cout << endl;
                flag = true;
            }
        }
    }
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    printZigZag(root);
    // queue<binaryTreeNode<int>*>q;
    // q.push(root -> left);
    // q.push(root -> right);
    // reverseQueue(q);
    // while(!q.empty())
    // {
    //     cout << q.front() -> data << " ";
    //     q.pop();
    // }
    return 0;
}