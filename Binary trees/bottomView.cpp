#include<iostream>
#include<queue>
#include<stack>
#include "binaryTreeNode.h"
using namespace std;

class dimensions
{
    public:
    int width;
    binaryTreeNode<int> *node;
};

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

void getWidth(binaryTreeNode<int> *root, int &minb, int &maxb, int hrdistance)
{
    if(root == nullptr)
    {
        return;
    }
    getWidth(root -> left, minb, maxb, hrdistance - 1);
    getWidth(root -> right, minb, maxb, hrdistance + 1);
    minb = min(minb, hrdistance);
    maxb = max(maxb, hrdistance);
    return;
}

vector<int> bottomView(binaryTreeNode<int> *root)
{
    vector<int>res;
    if(root == nullptr)
    {
        return res;
    }
    vector<stack<int> >bottom;
    int maxb = 0, minb = 0, hrdistance = 0;
    getWidth(root, minb, maxb, hrdistance);
    bottom.assign(maxb - minb + 1, stack<int>());
    queue<dimensions>pending;
    dimensions front;
    front.node = root;
    front.width = 0;
    pending.push(front);
    int pos = abs(minb);
    while(!pending.empty())
    {
        front = pending.front();
        pending.pop();
        bottom[front.width + pos].push(front.node -> data);
        if(front.node -> left != nullptr)
        {
            dimensions temp;
            temp.node = front.node -> left;
            temp.width = front.width - 1;
            pending.push(temp);
        }
        if(front.node -> right != nullptr)
        {
            dimensions temp;
            temp.node = front.node -> right;
            temp.width = front.width + 1;
            pending.push(temp);
        }
    }
    for(int i = 0; i < bottom.size(); i++)
    {
        res.push_back(bottom[i].top());
    }
    return res;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    vector<int> res = bottomView(root);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
