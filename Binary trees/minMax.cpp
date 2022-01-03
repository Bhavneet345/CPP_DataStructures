#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* takeinput()
{
    int data;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        binaryTreeNode<int> *front = pending.front();
        pending.pop();
        cin >> data;
        if(data != -1)
        {
            binaryTreeNode<int> *leftchild = new binaryTreeNode<int>(data);
            front -> left = leftchild;
            pending.push(leftchild);
        }
        else
        {
            front -> left = nullptr;
        }
        cin >> data;
        if(data != -1)
        {
            binaryTreeNode<int> *rightchild = new binaryTreeNode<int>(data);
            front -> right = rightchild;
            pending.push(rightchild);
        }
        else
        {
            front -> right = nullptr;
        }
    }
    return root;
}   

pair<int, int> getminAndMax(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        pair<int, int>p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
        pair<int, int>p;
        p.first = root -> data;
        p.second = root -> data;
        return p;
    }
    pair<int, int> left = getminAndMax(root -> left);
    pair<int, int> right = getminAndMax(root -> right);
    int minimum = min(root -> data, min(left.first, right.first));
    int maximum = max(root -> data, max(left.second, right.second));
    pair<int, int>p;
    p.first = minimum;
    p.second = maximum;
    return p;
} 

int main()
{
    binaryTreeNode<int> *root = takeinput();
    pair<int, int> p = getminAndMax(root);
    cout << "Minimum: " << p.first << endl << "Maximum: " << p.second;
    return 0;
}