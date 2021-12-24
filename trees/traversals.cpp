#include<iostream>
#include<queue>
#include "treeNode.h"
// 1 3 2 3 4 2 5 6 0 1 9 0 2 7 8 0 0 0 

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

void preOrder(treeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    cout << root -> data << " ";
    for(int i = 0; i < root -> children.size(); i++)
    {
        preOrder(root -> children[i]);
    }
    return;
}

void postOrder(treeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    for(int i = 0; i < root -> children.size(); i++)
    {
        postOrder(root -> children[i]);
    }
    cout << root -> data << " ";
}
int main()
{
    treeNode<int> *root = takeInput();
    preOrder(root);
    cout << endl;
    postOrder(root);
    return 0;
}