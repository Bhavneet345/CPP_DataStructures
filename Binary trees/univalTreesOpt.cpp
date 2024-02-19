#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

class Unival
{
    public:
    bool isunival;
    int total;
};

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

Unival helperUnivalTrees(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        Unival u;
        u.isunival = true;
        u.total = 0;
        return u;
    }
    Unival left = helperUnivalTrees(root -> left);
    Unival right = helperUnivalTrees(root -> right);
    Unival output;
    output.isunival = false;
    output.total = left.total + right.total;
    if(left.isunival && right.isunival)
    {
        if(root -> left != nullptr && root -> data != root -> left -> data)
        {
            return output;
        }
        if(root -> right != nullptr && root -> data != root -> right -> data)
        {
            return output;
        }
    }
    if(left.isunival && right.isunival)
    {
        output.total += 1;
        output.isunival = true;
        return output;
    }   
    return output;    
}

int countUnival(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    Unival output = helperUnivalTrees(root);
    return output.total;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    int res = countUnival(root);
    cout << res;
    return 0;
}