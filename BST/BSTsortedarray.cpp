#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* BSTfromArray(int *arr, int start, int end)
{
    if(start > end)
    {
        return nullptr;
    }
    int mid = (start + end) / 2;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(arr[mid]);
    root -> left = BSTfromArray(arr, start, mid - 1);
    root -> right = BSTfromArray(arr, mid + 1, end);
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
    return;
}

void preOrder(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
    return;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    binaryTreeNode<int> *root = BSTfromArray(arr, 0, n - 1);
    inOrder(root);
    cout << endl;
    preOrder(root);
    return 0;
}