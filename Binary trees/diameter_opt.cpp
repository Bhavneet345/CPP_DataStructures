#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;
// 10 20 30 40 50 -1 -1 -1 -1 -1 -1

binaryTreeNode<int>* takeinput()
{
    int data;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        binaryTreeNode<int> *front = pending.front();
        pending.pop();
        cin >> data;
        if(data != -1)
        {
            binaryTreeNode<int> *newnode = new binaryTreeNode<int>(data);
            pending.push(newnode);
            front -> left = newnode;
        }
        else
        {
            front -> left = nullptr;
        }
        cin >> data;
        if(data != -1)
        {
            binaryTreeNode<int> *newnode = new binaryTreeNode<int>(data);
            pending.push(newnode);
            front -> right = newnode;
        }
        else
        {
            front -> right = nullptr;
        }
    }
    return root;
}

//first = height, second = diameter
pair<int, int> heightDiameter(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        pair<int, int>p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int>left = heightDiameter(root -> left);
    pair<int, int>right = heightDiameter(root -> right);
    int lh = left.first, ld = left.second;
    int rh = right.first, rd = right.second;
    int rootD = lh + rh;
    int rootH = 1 + max(lh, rh);
    pair<int, int>p;
    p.first = rootH;
    p.second = max(rootD, max(ld, rd));
    return p;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    pair <int, int> p = heightDiameter(root);
    cout << "Height: " << p.first << endl << "Diameter: " << p.second; 
    return 0; 
}

