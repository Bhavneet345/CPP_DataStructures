#include<iostream>
#include<queue>
#include<stack>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* takeInput()
{
    queue<binaryTreeNode<int>*>pending;
    binaryTreeNode<int>*root, *front;
    int prevn1, n2, currn1, total;
    cin >> total;
    for(int i = 0; i < total - 1; i += 2)
    {
        if(i == 0)
        {
            cin >> prevn1 >> n2;
            root = new binaryTreeNode<int>(prevn1);
            root -> left = new binaryTreeNode<int>(n2);
            pending.push(root -> left);
            cin >> currn1 >> n2;
            if(currn1 != prevn1)
            {
                root -> right = nullptr;
            }
            else
            {
                root -> right = new binaryTreeNode<int>(n2);
                pending.push(root -> right);
            }
        }
        else
        {
            front = pending.front();
            pending.pop();
            cin >> prevn1 >> n2;
            front -> left = new binaryTreeNode<int>(n2);
            pending.push(front -> left);
            cin >> currn1 >> n2;
            if(currn1 != prevn1)
            {
                front -> right = nullptr;
            }
            else
            {
                root -> right = new binaryTreeNode<int>(n2);
                pending.push(root -> right);
            }
        }
    }
    while(!pending.empty())
    {
        pending.front() -> left = nullptr;
        pending.front() -> right = nullptr;
        pending.pop();
    }
    return root;
}

pair<binaryTreeNode<int>*, int>maxHeight(binaryTreeNode<int>*root)
{
    if(root == nullptr)
    {
        pair<binaryTreeNode<int>*, int>p;
        p.first = nullptr;
        p.second = 0;
        return p;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
        pair<binaryTreeNode<int>*, int>p;
        p.first = root;
        p.second = 1;
        return p;
    }
    pair<binaryTreeNode<int>*, int>left = maxHeight(root -> left);
    pair<binaryTreeNode<int>*, int>right = maxHeight(root -> right);
    pair<binaryTreeNode<int>*, int>output;
    if(left.second > right.second)
    {
        output.first = left.first;
        output.second = left.second + 1;
    }
    else
    {
        output.first = right.first;
        output.second = right.second + 1;
    }
    return output;
}

pair<pair<binaryTreeNode<int>*, binaryTreeNode<int>*>, pair<int, int> >helper(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        pair<pair<binaryTreeNode<int>*, binaryTreeNode<int>*>, pair<int, int> >p;
        p.first.first = nullptr;
        p.first.second = nullptr;
        p.second.first = 0;
        p.second.second = 0;
        return p;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
        pair<pair<binaryTreeNode<int>*, binaryTreeNode<int>*>, pair<int, int> >p;
        p.first.first = root;
        p.first.second = root;
        p.second.first = 1;
        p.second.second = 0;
        return p;
    }
    pair<pair<binaryTreeNode<int>*, binaryTreeNode<int>*>, pair<int, int> >left = helper(root -> left);
    pair<pair<binaryTreeNode<int>*, binaryTreeNode<int>*>, pair<int, int> >right = helper(root -> right);
    pair<pair<binaryTreeNode<int>*, binaryTreeNode<int>*>, pair<int, int> >output;
    int lh = left.second.first, ld = left.second.second;
    int rh = right.second.first, rd = right.second.second;
    int rootd = lh + rh;
    int outh = max(lh, rh) + 1;
    int outd = max(rootd, max(ld, rd));
    if(outd == rootd)
    {
        pair<binaryTreeNode<int>*, int>p1 = maxHeight(root -> left);
        if(p1.first == left.first.first && p1.first != nullptr)
        {
            output.first.first = left.first.first;
        }
        else if(p1.first != nullptr)
        {
            output.first.first = left.first.second;
        }
        else
        {
            output.first.first = root;
        }
        pair<binaryTreeNode<int>*, int>p2 = maxHeight(root -> right);
        if(p2.first == right.first.first && p2.first != nullptr)
        {
            output.first.second = right.first.first;
        }
        else if(p2.first != nullptr)
        {
            output.first.second = right.first.second;
        }
        else
        {
            output.first.second = root;
        }
        output.second.first = outh;
        output.second.second = outd;
    }
    else if(outd == ld)
    {
        output.first.first = left.first.first;
        output.first.second = left.first.second;
        output.second.first = outh;
        output.second.second = ld;
    }
    else
    {
        output.first.first = right.first.first;
        output.first.second = right.first.second;
        output.second.first = outh;
        output.second.second = rd;
    }
    return output;
}
    
void cycle(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    if(root -> left == nullptr && root -> right == nullptr)
    {
        cout << root -> data;
        return;
    }
    pair<pair<binaryTreeNode<int>*, binaryTreeNode<int>*>, pair<int, int> >p = helper(root);
    cout << p.first.first -> data << " " << p.first.second -> data;
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    cycle(root);
    return 0;
}