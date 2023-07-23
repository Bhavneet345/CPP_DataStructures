#include<iostream>
#include<queue>
#include<algorithm>
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

void elementsInRangeK1K2(binaryTreeNode<int> *root, int k1, int k2)
{
    if(root == nullptr)
    {
        return;
    }
    if(root -> data >= k1 && root -> data <= k2)
    {
        elementsInRangeK1K2(root -> left, k1, k2);
        cout << root -> data << " ";
        elementsInRangeK1K2(root -> right, k1, k2);
    }
    else if(root -> data < k1)
    {
        elementsInRangeK1K2(root -> right, k1, k2);
    }
    else if(root -> data > k2)
    {
        elementsInRangeK1K2(root -> left, k1, k2);
    }
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
    return 0;
}