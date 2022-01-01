#include<iostream>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int> *buildhelper(int *postorder, int *inorder, int PS, int PE, int IS, int IE)
{
    if(PS > PE || IS > IE)
    {
        return nullptr;
    }
    binaryTreeNode<int> *root = new binaryTreeNode<int>(postorder[PE]);
    int k = 0;
    for(k = IS; k <= IE; k++)
    {
        if(inorder[k] == root -> data)
        {
            break;
        }
    }
    root -> left = buildhelper(postorder, inorder, PS, PS + (k - IS) - 1, IS, k - 1);
    root -> right = buildhelper(postorder, inorder, PS + (k - IS), PE - 1, k + 1, IE);
    return root;
}

binaryTreeNode<int>* buildTree(int *postorder, int postlength, int *inorder, int inlength)
{
    binaryTreeNode<int> *root = buildhelper(postorder, inorder, 0, postlength - 1, 0, inlength - 1);
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
    int size;
    cin >> size;
    int *postorder = new int[size], *inorder = new int[size];
    for(int i = 0; i < size; i++)
    {
        cin >> postorder[i];
    }
    for(int i = 0; i < size; i++)
    {
        cin >> inorder[i];
    }
    binaryTreeNode<int> *root = buildTree(postorder, size, inorder, size);
    inOrder(root);
    return 0;
}