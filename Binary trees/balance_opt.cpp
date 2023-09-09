#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

class retBalance
{
    public:
    int height;
    bool balance;
};

binaryTreeNode<int>* takeinput()
{
    int data;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        binaryTreeNode<int> *front = pending.front();
        pending.pop();
        cin >> data;
        if(data != -1)
        {
            binaryTreeNode<int> *leftchild = new binaryTreeNode<int>(data);
            front -> left = leftchild;
            pending.push(leftchild);
        }
        else
        {
            front -> left = nullptr;
        }
        cin >> data;
        if(data != -1)
        {
            binaryTreeNode<int> *rightchild = new binaryTreeNode<int>(data);
            front -> right = rightchild;
            pending.push(rightchild);
        }
        else
        {
            front -> right = nullptr;
        }
    }
    return root;
} 

retBalance* helperisBalance(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        retBalance *ans = new retBalance();
        ans -> height = 0;
        ans -> balance = true;
        return ans;
    }
    bool flag = true;
    retBalance *ans1 = helperisBalance(root -> left), *ans2 = helperisBalance(root -> right);
    int lh = ans1->height, rh = ans2 -> height;
    if(!(ans1->balance && ans2->balance))
    {
        flag = false;
    }
    else if(abs(lh - rh) > 1)
    {
        flag = false;
    }
    retBalance *finalans = new retBalance();
    finalans -> balance = flag;
    finalans -> height = 1 + max(ans1 -> height, ans2->height);
    return finalans;
}

bool isBalanced(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return true;
    }
    retBalance *ans = helperisBalance(root);
    return ans -> balance;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    if(isBalanced(root))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}
