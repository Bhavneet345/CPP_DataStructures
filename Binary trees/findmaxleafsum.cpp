#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
#include "LCA.cpp"
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

int findSumofleaves(binaryTreeNode<int> *root, int leaf1, int leaf2)
{
    if(root == nullptr)
    {
        return 0;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
        if(root -> data == leaf1 || root -> data == leaf2)
        {
            return root -> data;
        }
        return 0;
    }
    int left = findSumofleaves(root -> left, leaf1, leaf2);
    int right = findSumofleaves(root -> right, leaf1, leaf2);
    return left + right + root -> data;
}


int main()
{
    binaryTreeNode<int> *root = takeinput();
    long long int sum = findMaxSumPath(root);
    cout << sum;
    // binaryTreeNode<int> *lca = getLCA(root, 9,2);
    // cout << findSumofleaves(lca, 9, 2);
    return 0;
}