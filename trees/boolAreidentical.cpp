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

bool areIdentical(treeNode<int> *root1, treeNode<int> *root2)
{
    if(root1 == nullptr && root2 == nullptr)
    {
        return true;
    }
    if(root1 == nullptr || root1 == nullptr)
    {
        return false;
    }
    if(root1 -> data != root2 -> data)
    {
        return false;
    }
    if(root1 -> children.size() != root2 -> children.size())
    {
        return false;
    }
    for(int i = 0; i < root1 -> children.size(); i++)
    {
        if(!areIdentical(root1 -> children[i], root2 -> children[i]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    treeNode<int> *root1 = takeInput(), *root2 = takeInput();
    if(areIdentical(root1, root2))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
