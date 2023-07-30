#include<iostream>
#include<algorithm>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int> *construct(int *arr, int start, int end)
{
    if(start > end)
    {
        return nullptr;
    }
    int mid = (start + end) / 2;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(arr[mid]);
    root -> left = construct(arr, start, mid - 1);
    root -> right = construct(arr, mid + 1, end);
    return root;
}

binaryTreeNode<int> *takeinput()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    binaryTreeNode<int> *root = construct(arr, 0, n - 1);
    return root;
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

void postOrder(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    cout << "Pre order  : ";
    preOrder(root);
    cout << endl;
    cout << "In order   : ";
    inOrder(root);
    cout << endl;
    cout << "Post order : ";
    postOrder(root);
    return 0;
}
