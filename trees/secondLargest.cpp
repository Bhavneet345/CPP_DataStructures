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


treeNode<int>* findsecondLarget(treeNode<int> *root)
{
    treeNode<int> *largest = new treeNode<int>(INT_MIN), *secondlargest = new treeNode<int>(INT_MIN);
    queue<treeNode<int>*> pending;
    pending.push(root);
    while(!pending.empty())
    {
        treeNode<int> *front = pending.front();
        pending.pop();
        for(int i = 0; i < front -> children.size(); i++)
        {
            pending.push(front -> children[i]);
        }
        if(front -> data > largest -> data)
        {
            secondlargest = largest;
            largest = front;
        }
        else if(front -> data > secondlargest -> data && front -> data < largest -> data) 
        {
            secondlargest = front;
        }
    }
    return secondlargest;
}

int main()
{
    treeNode<int> *root = takeInput();
    cout << findsecondLarget(root) -> data;
    return 0;
}