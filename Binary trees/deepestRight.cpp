#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

class info
{
    public:
    int height;
    bool isright;
    binaryTreeNode<int> *node;
};

binaryTreeNode<int>* takeInput()
{
    int data;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        int size = pending.size();
        while(size--)
        {
            binaryTreeNode<int> *front = pending.front();
            pending.pop();
            cin >> data;
            if(data != -1)
            {
                binaryTreeNode<int> *temp = new binaryTreeNode<int>(data);
                front -> left = temp;
                pending.push(front -> left);
            }
            else
            {
                front -> left = nullptr;
            }
            cin >> data;
            if(data != -1)
            {
                binaryTreeNode<int> *temp = new binaryTreeNode<int>(data);
                front -> right = temp;
                pending.push(front -> right);
            }
            else
            {
                front -> right = nullptr;
            }
        }
    }
    return root;
}

int findheight(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return max(findheight(root -> left), findheight(root -> right)) + 1;
}

binaryTreeNode<int>* deepestRightleaf(binaryTreeNode<int> *root)
{
    if(root == nullptr)
    {
        return root;
    }
    int height = findheight(root);
    if(height <= 1)
    {
        return nullptr;
    }
    binaryTreeNode<int> *ans = nullptr;
    queue<info>pending;
    info i;
    i.node = root;
    i.height = 1;
    i.isright = false;
    pending.push(i);
    while(!pending.empty())
    {
        info front = pending.front();
        pending.pop();
        if(front.isright && front.height == height)
        {
            ans = front.node;
        }
        if(front.node -> left != nullptr)
        {
            info temp;
            temp.height = front.height + 1;
            temp.isright = false;
            temp.node = front.node -> left;
            pending.push(temp);
        }
        if(front.node -> right != nullptr)
        {
            info temp;
            temp.height = front.height + 1;
            temp.isright = true;
            temp.node = front.node -> right;
            pending.push(temp);
        }
    }
    return ans;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    binaryTreeNode<int> *ans = deepestRightleaf(root);
    if(ans)
    {
        cout << ans -> data;
    }
    else
    {
        cout << -1;
    }
    return 0;
}