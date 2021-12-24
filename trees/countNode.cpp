#include<iostream>
#include<queue>
#include "treeNode.h"
using namespace std;

treeNode<int>* createTreeLevel()
{
    int rootdata, nodedata, nodes;
    cout << "Enter the data of root\n";
    cin >> rootdata;
    treeNode<int> *root = new treeNode<int>(rootdata);
    queue<treeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    while(!pending_nodes.empty())
    {
        treeNode<int> *front = pending_nodes.front();
        pending_nodes.pop();
        cout << "Enter the number of children of " << front->data << endl;
        cin >> nodes;
        for(int i = 1; i <= nodes; i++)
        {
            cout << "Enter the nodedata of " << i << "th child of " << (*front).data << endl;
            cin >> nodedata;
            treeNode<int> *child = new treeNode<int>(nodedata);
            front -> children.push_back(child);
            pending_nodes.push(child);
        }
    }
    return root;
}

int countnodes(treeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    int count = 1;
    for(int i = 0; i < root -> children.size(); i++)
    {
        count += countnodes(root -> children[i]);
    }
    return count;
}

int main()
{
    treeNode<int> *root = createTreeLevel();
    cout << countnodes(root);
    return 0;
}