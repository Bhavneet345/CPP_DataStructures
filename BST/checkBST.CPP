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

pair<bool ,pair<int, int> > isBSThelper(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        pair<bool, pair<int, int> >p;
        p.first = true;
        p.second.first = INT_MAX;
        p.second.second = INT_MIN;
        return p;
    }
    pair<bool, pair<int, int> >left = isBSThelper(root -> left);
    pair<bool, pair<int, int> >right = isBSThelper(root -> right);
    if(!(left.first && right.first))
    {
        pair<bool, pair<int, int> >p;
        p.first = false;
        p.second.first = left.second.second;
        p.second.second = right.second.first;
        return p;
    }
    pair<bool, pair<int, int> >output;
    output.second.first = min(root -> data, min(left.second.first, right.second.first));
    output.second.second = max(root -> data, max(left.second.second, right.second.second));
    output.first = ((root -> data > left.second.second) && (root -> data <= right.second.first));
    return output;
}

bool isBST(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return true;
    }
    pair<bool ,pair<int, int> > output = isBSThelper(root);
    return output.first;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    if(isBST(root))
    {
        cout << "true";
    }
    else 
    {
        cout << "false";
    }
    return 0;
}