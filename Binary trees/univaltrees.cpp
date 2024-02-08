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

bool isUnival(binaryTreeNode<int> *root, int element)
{
    if(root == nullptr)
    {
        return true;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
        if(root -> data == element)
        {
            return true;
        }
        return false;
    }
    if(root -> data != element)
    {
        return false;
    }
    return isUnival(root -> left, element) && isUnival(root -> right, element);
}

int countUnival(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int leftcount = countUnival(root -> left);
    int rightcount = countUnival(root -> right);
    int output = leftcount + rightcount;
    if(isUnival(root, root -> data))
    {
        return 1 + output;
    }
    return output;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int res = countUnival(root);
    cout << res;
    return 0;
}