#include<iostream>
#include<queue>
#include "treeNode.h"
using namespace std;

//child wise input approach
treeNode<int>* createTree()
{
    int rootdata, n;
    cout << "Enter Root data\n";
    cin >> rootdata;
    treeNode<int> *root = new treeNode<int>(rootdata);
    cout << "Enter number of children of "<< rootdata << "\n";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        root->children.push_back(createTree());
    }
    return root;
}

//level wise input
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

//levelWiseprint
void printLevelWise(treeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    queue<treeNode<int>*> pending;
    pending.push(root);
    while(!pending.empty())
    {
        treeNode<int> *front = pending.front();
        pending.pop();
        cout << front -> data << ":";
        for(int i = 0; i < front -> children.size(); i++)
        {
            pending.push(front -> children[i]);
            cout << front -> children[i] -> data;
            if(i != front -> children.size() - 1)
            {
                cout << ",";
            }
        }
        cout << endl;
    }
}

void print(treeNode<int> *root)
{
    //to handle edge case not base case
    if(root == nullptr)
    {
        return;
    }
    cout << root -> data << ":";
    for(int i = 0; i < root -> children.size(); i++)
    {
        cout << root -> children[i] -> data << " ";
    }
    cout << endl;
    for(int i = 0; i < root -> children.size(); i++)
    {
        print(root -> children[i]);
    }
    return;
}

int main()
{
    treeNode<int> *root = createTreeLevel();
    printLevelWise(root);
    return 0;
}