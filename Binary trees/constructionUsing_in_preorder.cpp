#include<iostream>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* buildhelper(int *preorder, int *inorder, int PS, int PE, int IS, int IE)
{
    if(PS > PE || IS > IE)
    {
        return nullptr;
    }
    binaryTreeNode<int> *root = new binaryTreeNode<int>(preorder[PS]);
    int k = 0;
    for(k = IS; k <= IE; k++)
    {
        if(inorder[k] == preorder[PS])
        {
            break;
        }
    }
    root -> left = buildhelper(preorder, inorder, PS + 1, PS + (k - IS), IS, k - 1);
    root -> right = buildhelper(preorder, inorder, PS + (k - IS) + 1, PE, k + 1, IE);
    return root;
}

binaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    binaryTreeNode<int> *root = buildhelper(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
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

int main()
{
    int size;
    cin >> size;
    int *preorder = new int[size], *inorder = new int[size];
    for(int i = 0; i < size; i++)
    {
        cin >> preorder[i];
    }
    for(int i = 0; i < size; i++)
    {
        cin >> inorder[i];
    }
    binaryTreeNode<int> *root = buildTree(preorder, size, inorder, size);
    preOrder(root);
    cout << endl;
    inOrder(root);
    return 0;
}