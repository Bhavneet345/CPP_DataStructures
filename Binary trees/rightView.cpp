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

void rightView(binaryTreeNode<int> *root, int level, int &maxlevel, vector<int> &res)
{
    if(root == nullptr)
    {
        return;
    }
    if(maxlevel < level)
    {
        maxlevel = level;
        res.push_back(root -> data);
    }
    rightView(root -> right, level + 1, maxlevel, res);
    rightView(root -> left, level + 1, maxlevel, res);
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    int maxlevel = 0;
    vector<int> res;
    rightView(root, 1, maxlevel, res);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
