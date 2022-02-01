#include<iostream>
#include<queue>
#include "binaryTreeNode.h"

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

pair<long long int, long long int> maxsumbwLeaf(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = -1;
        return p;
    }
    pair<long long int, long long int> left = maxsumbwLeaf(root -> left);
    pair<long long int, long long int> right = maxsumbwLeaf(root -> right);
    if(root -> left != nullptr && root -> right != nullptr)
    {
        pair<long long int, long long int> output;
        long long int pathfromroot = root -> data + left.first + right.first;
        output.first = max(left.first, right.first) + root -> data;
        output.second = max(pathfromroot, max(left.second, right.second));
        return output;
    }
    if(root -> left != nullptr)
    {
        left.first += root -> data;
        return left;
    }
    if(root -> right != nullptr)
    {
        right.first += root -> data;
        return right;
    }
    pair<long long int, long long int> p;
    p.first = root -> data;
    p.second = -1;
    return p;
}

long long int returnMaxSumpath(binaryTreeNode<int> *root)
{
    pair<long long int, long long int> p = maxsumbwLeaf(root);
    return p.second;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    cout << returnMaxSumpath(root);
    return 0;
}