#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

class isBSThelper
{
    public:
    bool isBST;
    int height, max, min;
};

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

isBSThelper largestBSThelper(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        isBSThelper b;
        b.height = 0;
        b.isBST = true;
        b.max = INT_MIN;
        b.min = INT_MAX;
        return b;
    }
    isBSThelper left = largestBSThelper(root -> left);
    isBSThelper right = largestBSThelper(root -> right);
    if(!(root -> data > left.max && left.isBST))
    {
        left.isBST = false;
    }
    if(!(root -> data < right.min && right.isBST))
    {
        right.isBST = false;
    }
    if(!right.isBST || right.min < root -> data || !left.isBST || root -> data < left.max)
    {
        if(left.height > right.height)
        {
            left.isBST = false;
            return left;
        }
        else
        {
            right.isBST = false;
            return right;
        }
    }
    isBSThelper output;
    output.isBST = true;
    output.max = max(root -> data, max(right.max, left.max));
    output.min = min(root -> data, min(left.min, right.min));
    output.height = max(left.height, right.height) + 1;
    return output;
}

int largestBSTSubtree(binaryTreeNode<int> *root)
{
    return largestBSThelper(root).height;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int res = largestBSTSubtree(root);
    cout << res;
    return 0;
}