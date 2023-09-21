#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* takeInput()
{
    int data;
    cin >> data;
    queue<binaryTreeNode<int>*>pending;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data), *front;
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

void bottomViewhelper(binaryTreeNode<int> *root, int &maxlevel, int level, vector<int> &res)
{
    if(root == nullptr)
    {
        return;
    }
    bottomViewhelper(root -> right, maxlevel, level, res);
    if(maxlevel <= level)
    {
        res.push_back(root -> data);
        maxlevel += 1;
    }
    bottomViewhelper(root -> left, maxlevel, level + 1, res);
}

vector<int> bottomright(binaryTreeNode<int> *root)
{
    vector<int> res;
    int maxlevel = 0;
    bottomViewhelper(root, maxlevel, 0, res);
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    vector<int> res = bottomright(root);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
