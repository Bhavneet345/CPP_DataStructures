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

treeNode<int>* nextGreater(treeNode<int> *root, int x)
{
    if(root == nullptr)
    {
        return root;
    }
    treeNode<int> *resultNode = new treeNode<int>(INT_MAX), *tempnode;
    int data = INT_MAX;
    if(root -> data > x)
    {
        data = root -> data;
        resultNode = root;
    }
    for(int i = 0; i < root -> children.size(); i++)
    {
        tempnode = nextGreater(root -> children[i], x);
        if(tempnode != nullptr)
        {
            if(tempnode -> data > x && tempnode -> data < resultNode -> data)
            {
                resultNode = tempnode;
                data = tempnode -> data;
            }
        }
    }
    if(resultNode -> data == INT_MAX)
    {
        return nullptr;
    }
    return resultNode;
}

int main()
{
    treeNode<int> *root = takeInput();
    int x;
    cin >> x;
    root = nextGreater(root , x);
    if(root != nullptr)
    {
        cout << root -> data;
    }
    delete root;
    return 0;
}