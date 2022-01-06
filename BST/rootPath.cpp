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
    binaryTreeNode<int> *front;
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

vector<int>* getPath(binaryTreeNode<int> *root, int k)
{
    vector<int> *res = new vector<int>;
    if(root == nullptr)
    {
        res = nullptr;
        return res;
    }
    else if(root -> data == k)
    {
        res -> push_back(root -> data);
        return res;
    }
    vector<int> *left = getPath(root -> left, k);
    vector<int> *right = getPath(root -> right, k);
    if(left)
    {
        left -> push_back(root -> data);
        return left;
    }
    else if(right)
    {
        right -> push_back(root -> data);
        return right;
    }
    return nullptr;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *res = getPath(root, k);
    for(int i = 0; i < res -> size(); i++)
    {
        cout << (*res)[i] << " ";
    }
    return 0;
}