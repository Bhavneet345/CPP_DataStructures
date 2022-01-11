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

int deepestLeavesSum(binaryTreeNode<int>* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    int ans = 0;
    while(!pending.empty())
    {
        ans = 0;
        int size = pending.size();
        while(size--)
        {
            binaryTreeNode<int> *front = pending.front();
            pending.pop();
            ans += front -> data;
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
    return ans;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    cout << deepestLeavesSum(root);
    return 0;
}