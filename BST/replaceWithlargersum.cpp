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

int Sum(binaryTreeNode<int> *root, int sum)
{
    if((root) == nullptr)
    {
        return sum;
    }
    sum = Sum(root -> right, sum);
    sum += (root) -> data;
    (root) -> data = sum;
    sum = Sum((root) -> left, sum);
    return sum;
}

binaryTreeNode<int>* replaceWithLargerNodesSum(binaryTreeNode<int> *root)
{
    int sum = 0;
    sum = Sum(root, sum);
    return root;
}

void inOrder(binaryTreeNode<int> *root) 
{
    if(root == nullptr)
    {
        return;
    }
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    inOrder(root);
    root = replaceWithLargerNodesSum(root);
    cout << endl;
    inOrder(root);
    return 0;
}