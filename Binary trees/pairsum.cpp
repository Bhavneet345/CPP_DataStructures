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

vector<int> retFlat(binaryTreeNode<int> *root)
{
    queue<binaryTreeNode<int>*>pending;
    binaryTreeNode<int> *front;
    pending.push(root);
    vector<int>tree;
    while(!pending.empty())
    {
        front = pending.front();
        pending.pop();
        tree.push_back(front -> data);
        if(front -> left != nullptr)
        {
            pending.push(front -> left);
        }
        if(front -> right != nullptr)
        {
            pending.push(front -> right);
        }
    }   
    return tree;
}

void helper(vector<int>arr, int sum)
{
    int i = 0, j = arr.size() - 1;
    while(i < j)
    {
        if(arr[i] + arr[j] < sum)
        {
            i++;
        }
        else if(arr[i] + arr[j] > sum)
        {
            j--;
        }
        else
        {
            cout << arr[i] << " " << arr[j] << endl;
            i++;
            j--;
        }
    }
    return;
}

void pairSum(binaryTreeNode<int> *root, int sum)
{
    if(root == nullptr)
    {
        return;
    }
    vector<int> tree = retFlat(root);
    sort(tree.begin(), tree.end());
    helper(tree, sum);
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    return 0;
}