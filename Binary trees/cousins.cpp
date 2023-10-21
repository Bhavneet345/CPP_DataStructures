#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

class childInfo
{
    public:
    binaryTreeNode<int> *parent;
    int height; 
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

bool isCousin(binaryTreeNode<int> *root, int p, int q)
{
    if(root == nullptr)
    {
        return false;
    }
    if(root -> left == nullptr || root -> right == nullptr)
    {
        return false;
    }
    if(root -> left -> data == p || root -> right -> data == q)
    {
        return false;
    }
    childInfo parent1, parent2;
    parent1.parent = nullptr, parent2.parent = nullptr;
    queue<pair<binaryTreeNode<int>*, int> >pending;
    pair<binaryTreeNode<int>*, int>temp;
    pair<binaryTreeNode<int>*, int>front;
    temp.first = root;
    temp.second = 0;
    pending.push(temp);
    while(!pending.empty())
    {
        front = pending.front();
        pending.pop();
        if(front.first -> left != nullptr)
        {
            if(front.first -> left -> data == p || front.first -> left -> data == q)
            {
                if(parent1.parent == nullptr)
                {
                    parent1.parent = front.first;
                    parent1.height = front.second;
                }
                else
                {
                    parent2.parent = front.first;
                    parent2.height = front.second;
                    break;
                }
            }
            pair<binaryTreeNode<int>*, int>temp1;
            temp1.first = front.first -> left;
            temp1.second = front.second + 1;
            pending.push(temp1);
        }
        if(front.first -> right != nullptr)
        {
            if(front.first -> right -> data == p || front.first -> right -> data == q)
            {
                if(parent1.parent == nullptr)
                {
                    parent1.parent = front.first;
                    parent1.height = front.second;
                }
                else
                {
                    parent2.parent = front.first;
                    parent2.height = front.second;
                    break;
                }
            }
            pair<binaryTreeNode<int>*, int>temp1;
            temp1.first = front.first -> right;
            temp1.second = front.second + 1;
            pending.push(temp1);
        }
    }
    if(parent1.parent == nullptr || parent2.parent == nullptr)
    {
        return false;
    }
    if(parent1.height == parent2.height && parent1.parent -> data != parent2.parent -> data)
    {
        return true;
    }
    return false;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    int p, q;
    cin >> p >> q;
    if(isCousin(root, p, q))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}