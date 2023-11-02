#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* takeInput()
{
    int data;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        int size = pending.size();
        while(size--)
        {
            binaryTreeNode<int> *front = pending.front();
            pending.pop();
            cin >> data;
            if(data != -1)
            {
                binaryTreeNode<int> *temp = new binaryTreeNode<int>(data);
                front -> left = temp;
                pending.push(front -> left);
            }
            else
            {
                front -> left = nullptr;
            }
            cin >> data;
            if(data != -1)
            {
                binaryTreeNode<int> *temp = new binaryTreeNode<int>(data);
                front -> right = temp;
                pending.push(front -> right);
            }
            else
            {
                front -> right = nullptr;
            }
        }
    }
    return root;
}

binaryTreeNode<int>* findLCA(binaryTreeNode<int> *root, int node1, int node2)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    if(root -> data == node1 || root -> data == node2)
    {
        return root;
    }
    binaryTreeNode<int> *left = findLCA(root -> left, node1, node2);
    binaryTreeNode<int> *right = findLCA(root -> right, node1, node2);
    if(left && right)
    {
        return root;
    }
    if(left)
    {
        return left;
    }
    return right;
}

int height(binaryTreeNode<int> *root, int node)
{
    if(root == nullptr)
    {
        return 0;
    }
    if(root -> data == node)
    {
        return 1;
    }
    int left = height(root -> left, node);
    int right = height(root -> right, node);
    if(left)
    {
        return left + 1;
    }
    else if(right)
    {
        return right + 1;
    }
    return 0;
}

int findDistanceBetweenNodes(binaryTreeNode<int> *root, int node1, int node2)
{
    if(root == nullptr)
    {
        return 0;
    }
    binaryTreeNode<int> *lca = findLCA(root, node1, node2);
    int node1height = height(lca, node1) - 1;
    int node2height = height(lca, node2) - 1;
    if(node1height < 0 || node2height < 0)
    {
        return -1;
    }
    return node1height + node2height;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int node1, node2;
    cin >> node1 >> node2;
    int distance = findDistanceBetweenNodes(root, node1, node2);
    cout << distance;
    return 0;
}