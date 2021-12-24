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


bool isPresent(treeNode<int>* root, int x) {
    // Write your code here
    if(root == nullptr)
    {
        return false;
    }
    if(root -> data == x)
    {
        return true;
    }
    for(int i = 0; i < root -> children.size(); i++)
    {
        bool present = isPresent(root -> children[i], x);
        if(present)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    treeNode<int> *root = takeInput();
    int x;
    cin >> x;
    if(isPresent(root, x))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}