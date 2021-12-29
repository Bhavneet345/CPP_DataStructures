#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* takeInput()
{
    int data, leftdata, rightdata;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        binaryTreeNode<int> *front = pending.front();
        pending.pop();
        cout << "Enter left child of " << front -> data << endl;
        cin >> leftdata;
        if(leftdata != -1)
        {
            front -> left = new binaryTreeNode<int>(leftdata);
            pending.push(front -> left);
        }
        else
        {
            front -> left = nullptr;
        }
        cout << "Enter right child of " << front -> data << endl;
        cin >> rightdata;
        if(rightdata != -1)
        {
            front -> right = new binaryTreeNode<int>(rightdata);
            pending.push(front -> right);
        }
        else
        {
            front -> right = nullptr;   
        }
    }
    return root;
}


int countNodes(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int count = 1;
    count += countNodes(root -> left) + countNodes(root -> right);
    return count;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    cout << countNodes(root);
    return 0;
}