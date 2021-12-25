#include<iostream>
#include<queue>
#include "treeNode.h"
using namespace std;

treeNode<int>* takeInput()
{
    int rootdata, nodedata, nodes;
    cin >> rootdata;
    treeNode<int> *root = new treeNode<int>(rootdata);
    queue<treeNode<int>*>pending;
    pending.push(root);
    while (!pending.empty())
    {
        treeNode<int> *front = pending.front();
        pending.pop();
        cin >> nodes;
        for(int i = 0; i < nodes; i++)
        {
            cin >> nodedata;
            treeNode<int> *child = new treeNode<int>(nodedata);
            front -> children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}

int getLargeNodeCount(treeNode<int> *root, int x)
{
    if(root == nullptr)
    {
        return 0;
    }
    int count = 0;
    if(root -> data > x)
    {
        count = 1;
    }
    for(int i = 0; i < root -> children.size(); i++)
    {
        count += getLargeNodeCount(root -> children[i], x);
    }
    return count;
}

int main()
{
    treeNode<int> *root = takeInput();
    int x;
    cin >> x;
    cout << getLargeNodeCount(root, x);
    return 0;
}