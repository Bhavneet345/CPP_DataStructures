#include<iostream>
#include<queue>
#include<stack>
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

void getBreadth(binaryTreeNode<int> *root, int &minb, int &maxb, int hrdistance)
{
    if(root == nullptr)
    {
        return;
    }
    if(root -> left)
    {
        getBreadth(root -> left, minb, maxb, hrdistance - 1);
    }
    if(root -> right)
    {
        getBreadth(root -> right, minb, maxb, hrdistance + 1);
    }
    minb = min(hrdistance, minb);
    maxb = max(hrdistance, maxb);
    return;
}

void topView(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return;
    }
    int maxb = 0, minb = 0, hrdistance = 0;
    getBreadth(root, minb, maxb, hrdistance);
    int pos = abs(minb);
    pair<binaryTreeNode<int>*, int>temp;
    queue<pair<binaryTreeNode<int>*, int> >pending;
    temp.first = root, temp.second = 0;
    pending.push(temp);
    vector<int>visited((maxb - minb) + 1, -1);
    pair<binaryTreeNode<int>*, int>front;
    while(!pending.empty())
    {
        front = pending.front();
        pending.pop();
        if(visited[front.second + pos] == -1)
        {
            visited[front.second + pos] = front.first -> data;
        }
        if(front.first -> left != nullptr)
        {
            pair<binaryTreeNode<int>*, int>temp1;
            temp1.first = front.first -> left;
            temp1.second = front.second - 1;
            pending.push(temp1);
        }
        if(front.first -> right != nullptr)
        {
            pair<binaryTreeNode<int>*, int>temp2;
            temp2.first = front.first -> right;
            temp2.second = front.second + 1;
            pending.push(temp2);   
        }
    }
    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i] != -1)
        {
            cout << visited[i] << " ";
        }
    }
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    topView(root);
    return 0;
}