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

void helper(binaryTreeNode<int> *root, vector<int> &res)
{
    if(root == nullptr)
    {
        return;
    }
    helper(root -> left, res);
    res.push_back(root -> data);
    helper(root -> right, res);
}

binaryTreeNode<int> *inorderSuccesor(binaryTreeNode<int> *root, int node)
{
    if(root == nullptr)
    {
        return root;
    }
    vector <int> res;
    helper(root, res);
    int i = 0;
    for(i = 0; i < res.size(); i++)
    {
        if(res[i] == node)
        {
            break;
        }
    }
    if(i == res.size() || i == res.size() - 1)
    {
        return nullptr;
    }
    binaryTreeNode<int> *ans = new binaryTreeNode<int>(res[i + 1]);
    return ans;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    int data;
    cin >> data;
    binaryTreeNode<int> *res = inorderSuccesor(root,data );
    if(res == nullptr)
    {
        cout << "NULL";
    }
    else
    {
        cout << res -> data;
    }
    return 0;
}