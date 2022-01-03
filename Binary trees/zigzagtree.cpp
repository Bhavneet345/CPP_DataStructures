#include<iostream>
#include<queue>
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

void reverseQueue(queue<binaryTreeNode<int>*> &nodes)
{
    if(nodes.empty())
    {
        return;
    }
    binaryTreeNode<int> *front= nodes.front();
    nodes.pop();
    reverseQueue(nodes);
    nodes.push(front);
    return;
}

void zigZagOrder(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    int levelcount = 1;
    queue<binaryTreeNode<int>*>levels;
    binaryTreeNode<int> *front;
    levels.push(root);
    levels.push(nullptr);
    while(!levels.empty())
    {
        front = levels.front();
        levels.pop();
        if(front == nullptr)
        {
            if(levels.empty())
            {
                return;
            }
            reverseQueue(levels);
            levels.push(nullptr);
            ++levelcount;
            cout << endl;
        }  
        else
        {
            cout << front -> data << " ";
            if(levelcount % 2 != 0)
            {
                if(front -> left != nullptr)
                {
                    levels.push(front -> left);
                }
                if(front -> right != nullptr)
                {
                    levels.push(front -> right);
                }
            }
            else
            {
                if(front -> right != nullptr)
                {
                    levels.push(front -> right);
                }
                if(front -> left != nullptr)
                {
                    levels.push(front -> left);
                } 
            }
        }
    }
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    zigZagOrder(root);
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