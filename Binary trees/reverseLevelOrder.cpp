#include<iostream>
#include<queue>
#include<stack>
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

vector<int> reverseLevelOrder(binaryTreeNode<int> *root)
{
    vector<int>res;
    if(root == nullptr)
    {
        return res;
    }
    queue<binaryTreeNode<int>*>pending;
    stack<binaryTreeNode<int>*>nodes;
    binaryTreeNode<int>*front;
    pending.push(root);
    while(!pending.empty())
    {
        front = pending.front();
        pending.pop();
        nodes.push(front);
        if(front -> left != nullptr)
        {
            pending.push(front -> left);
        }
        if(front -> right != nullptr)
        {
            pending.push(front -> right);
        }
    }
    while(!nodes.empty())
    {
        res.push_back(nodes.top() -> data);
        nodes.pop();
    }
    return res;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    vector<int> res = reverseLevelOrder(root);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}