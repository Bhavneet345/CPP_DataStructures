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

void sumTreeHelper(binaryTreeNode<int> *root, vector<int> &res)
{
    if(root == nullptr)
    {
        return;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
        res.push_back(0);
        return;
    }
    else if(root -> left != nullptr && root -> right != nullptr)
    {
        res.push_back(root -> left -> data + root -> right -> data);
    }
    else if(root -> left != nullptr)
    {
        res.push_back(root -> left -> data);
    }
    else if(root -> right != nullptr)
    {
        res.push_back(root -> right -> data);
    }
    sumTreeHelper(root -> left, res);
    sumTreeHelper(root -> right, res);
}

vector<int> sumTree(binaryTreeNode<int> *root)
{
    vector<int> res;
    if(root == nullptr)
    {
        return res;
    }
    sumTreeHelper(root, res);
    return res;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    vector<int> res = sumTree(root);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}