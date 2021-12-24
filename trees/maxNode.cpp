#include<iostream>
#include<queue>
#include "treeNode.h"

treeNode<int>* takeInput()
{
    int rootData, nodes, nodeData;
    cout << "Enter the data of root\n";
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    queue<treeNode<int> *> pending;
    pending.push(root);
    while(!pending.empty())
    {
        treeNode<int> *front = pending.front();
        pending.pop();
        cout << "Enter the number of children of root " << front -> data << endl;
        cin >> nodes;
        for(int i = 0; i < nodes; i++)
        {
            cout << "Enter the nodedata of " << i + 1 << "th child of " << (*front).data << endl;
            cin >> nodeData;
            treeNode <int> *child = new treeNode<int>(nodeData);
            front->children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}

treeNode<int>* maxNode(treeNode<int> *root)
{
    int max = INT_MIN;
    treeNode<int> *maxNode = nullptr;
    queue<treeNode<int> *>pending;
    pending.push(root);
    while(!pending.empty())
    {
        treeNode<int> *front = pending.front();
        pending.pop();
        if(max < front -> data)
        {
            maxNode = front;
            max = front -> data;
        }
        for(int i = 0; i < front -> children.size(); i++)
        {
            pending.push(front -> children[i]);
        }
    }
    return maxNode;
}

int main()
{
    treeNode<int> *root = takeInput();
    cout << maxNode(root)->data;
    return 0;
}