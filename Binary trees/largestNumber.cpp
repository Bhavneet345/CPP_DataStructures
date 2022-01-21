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

void convertTovect(binaryTreeNode<int> *root, vector<int> &res)
{
    if(root == nullptr)
    {
        return;
    }
    res.push_back(root -> data);
    convertTovect(root -> left, res);
    convertTovect(root -> right, res);
    return;
}

bool compare(int a, int b)
{
    string x = to_string(a);
    string y = to_string(b);

    string xy = x + y;
    string yx = y + x;

    return (xy.compare(yx) > 0) ? 1 : 0;
}

string printLargest(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return " ";
    }
    vector<int> res;
    convertTovect(root, res);
    sort(res.begin(), res.end(), compare);
    string output;
    int count = 0;
    for(int i = 0; i < res.size(); i++)
    {
        output += to_string(res[i]);
        if(res[i] == 0)
        {
            ++count;
        }
    }
    if(count == res.size() && root != nullptr)
    {
        return "0";
    }
    return output;
}

int main()
{
    binaryTreeNode<int> *root = takeinput();
    string output = printLargest(root);
    cout << output;
    return 0;
}