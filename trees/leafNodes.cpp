#include<iostream>
#include<queue>
#include "treeNode.h"

treeNode<int>* takeInput()
{
    int rootData, nodes, nodeData;
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    queue<treeNode<int> *> pending;
    pending.push(root);
    while(!pending.empty())
    {
        treeNode<int> *front = pending.front();
        pending.pop();
        cin >> nodes;
        for(int i = 0; i < nodes; i++)
        {
            cin >> nodeData;
            treeNode <int> *child = new treeNode<int>(nodeData);
            front->children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}

int leafNodes(treeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    else if(root -> children.size() == 0)
    {
        return 1;
    }
    int leafcount = 0;
    for(int i = 0; i < root -> children.size(); i++)
    {
        leafcount += leafNodes(root -> children[i]);
    }
    return leafcount;
}

int main()
{
    treeNode<int> *root = takeInput();
    cout << leafNodes(root);
    return 0;
}