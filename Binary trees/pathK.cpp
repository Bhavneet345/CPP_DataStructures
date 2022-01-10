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

void getPath(binaryTreeNode<int> *root, int k, vector<int>&res)
{
    if(root == nullptr)
    {
        return;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
       if(k == root -> data)
       {
           res.push_back(root -> data);
           for(int i = 0; i < res.size(); i++)
           {
               cout << res[i] << " ";
           }
           cout << endl;
           res.pop_back();
       }
       return;
    }
   res.push_back(root -> data);
   getPath(root -> left, k - root -> data, res);
   getPath(root -> right, k - root -> data, res);
   res.pop_back();
   return;
}

void rootToLeafPathsSumToK(binaryTreeNode<int> *root, int k)
{
    vector<int>res;
    getPath(root, k, res);
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    rootToLeafPathsSumToK(root, k);
    return 0;
}