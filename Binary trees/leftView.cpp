#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* takeinput()
{
    int data;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data), *front;
    queue<binaryTreeNode<int>*>pending;
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

int getHeight(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return max(getHeight(root -> right), getHeight(root -> left)) + 1;
}

void leftView(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    int height = getHeight(root);
    vector<int>visited(height, -1);
    pair<binaryTreeNode<int>*,int>front;
    front.first = root;
    front.second = 1;
    queue<pair<binaryTreeNode<int>*,int> >pending;
    pending.push(front);
    while(!pending.empty())
    {
        front = pending.front();
        pending.pop();
        if(visited[front.second - 1] == -1)
        {
            visited[front.second - 1] = front.first -> data;
            cout << front.first -> data << " ";
        }
        if(front.first -> left != nullptr)
        {
            pair<binaryTreeNode<int>*,int>temp;   
            temp.first = front.first -> left;
            temp.second = front.second + 1;
            pending.push(temp);
        }
        if(front.first -> right != nullptr)
        {
            pair<binaryTreeNode<int>*,int>temp;
            temp.first = front.first -> right;
            temp.second = front.second + 1;   
            pending.push(temp);
        }
    }
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    leftView(root);
    return 0;
}
