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

void helper(treeNode<int> **root, int k)
{
    if(root == nullptr)
    {
        return;
    }
    (*root) -> data = k;
    for(int i = 0; i < (*root) -> children.size(); i++)
    {
        helper(&(*root) -> children[i], k + 1);
    }
    return;
}

void replaceWithDepthValue(treeNode<int> **root) 
{
    if(root == nullptr)
    {
        return;
    }
    helper(&(*root), 0);
}

void printLevelwise(treeNode<int> *root)
{
    queue<treeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        treeNode<int> *front = pending.front();
        cout << front -> data << " ";
        pending.pop();
        for(int i = 0; i < front -> children.size(); i++)
        {
            pending.push(front -> children[i]);
        }
    }
    return;
}

int main()
{
    treeNode<int> *root = takeInput();
    printLevelwise(root);
    replaceWithDepthValue(&root);
    cout << endl;
    printLevelwise(root);
    return 0;
}

