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

treeNode<int>* maxChildsum(treeNode<int> *root)
{
    if(root == nullptr)
    {
        return root;
    }
    int sum = root -> data, max = INT_MIN;
    queue<treeNode<int> *> pending;
    for(int i = 0; i < root -> children.size(); i++)
    {
        sum += root -> children[i] -> data;
        pending.push(root -> children[i]);
    }
    max = sum;
    treeNode<int> *maxnode = root;
    while(!pending.empty())
    {
        treeNode<int> *front = pending.front();
        pending.pop();
        sum = front -> data;
        for(int i = 0; i < front -> children.size(); i++)
        {
            sum += front -> children[i]->data;
            pending.push(front -> children[i]);
        }
        if(max < sum)
        {
            max = sum;
            maxnode = front;
        }
    }
    return maxnode;
}

int main()
{
    treeNode<int> *root = takeInput();
    treeNode<int> *maxnode = maxChildsum(root);
    cout << maxnode -> data;
    return 0;
}