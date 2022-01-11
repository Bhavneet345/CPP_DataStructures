#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

class pathInfo
{
    public:
    binaryTreeNode<int> *node;
    string way;
};

binaryTreeNode<int>* takeInput()
{
    int data;
    cin >> data;
    queue<binaryTreeNode<int>*>pending;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data), *front;
    pending.push(root);
    while(!pending.empty())
    {
        front = pending.front();
        pending.pop();
        cin >> data;
        if(data != -1)
        {
            front -> left = new binaryTreeNode<int>(data);
            pending.push(front -> left);
        }
        else
        {
            front -> left = nullptr;
        }
        cin >> data;
        if(data != -1)
        {
            front -> right = new binaryTreeNode<int>(data);
            pending.push(front -> right);
        }
        else
        {
            front -> right = nullptr;
        }
    }
    return root;
}

void depth(binaryTreeNode<int> *root, int distancefromroot)
{
    if(root == nullptr)
    {
        return;
    }
    if(distancefromroot == 0)
    {
        cout << root -> data << endl;
        return;
    }
    depth(root -> left, distancefromroot - 1);
    depth(root -> right, distancefromroot - 1);
    return;
}

vector<pathInfo>* getPath(binaryTreeNode<int> *root, int node)
{
    if(root == nullptr)
    {
        return nullptr;
    }
    vector<pathInfo> *res = new vector<pathInfo>;
    pathInfo p;
    if(root -> data == node)
    {
        p.node = root;
        p.way = "";
        res->push_back(p);
        return res;
    }
    vector<pathInfo> *left = getPath(root -> left, node);
    vector<pathInfo> *right = getPath(root -> right, node);
    if(left != nullptr)
    {
        p.node = root;
        p.way = "left";
        left->push_back(p);
        return left;
    }
    else if(right != nullptr)
    {
        p.node = root;
        p.way = "right";
        right->push_back(p);
        return right;
    }
    return nullptr;
}

void nodesAtDistanceK(binaryTreeNode<int> *root, int node, int k)
{
    if(root == nullptr)
    {
        return;
    }
    vector<pathInfo> *res = getPath(root, node);
    if(res == nullptr)
    {
        return;
    }
    binaryTreeNode<int> *target;
    string way;
    for(int i = 0; i < res -> size(); i++)
    {
        int distancefromTargetNode = i;
        target = res -> at(i).node;
        way = res -> at(i).way;
        if(distancefromTargetNode - k == 0)
        {
            depth(target, 0);
        }
        else if(way == "right")
        {
            depth(target -> left, k - distancefromTargetNode - 1);
        }
        else if(way == "left")
        {
            depth(target -> right, k - distancefromTargetNode - 1);
        }
        else if(way.empty())
        {
            depth(target, k);
        }
    }
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int node, k;
    cin >> node >> k;
    nodesAtDistanceK(root, node, k);
    return 0;
}
