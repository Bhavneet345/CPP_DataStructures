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

// int getWidth(binaryTreeNode<int> *root, binaryTreeNode<int> *node)
// {
//     if(root == nullptr)
//     {
//         return INT_MAX;
//     }
//     if(root == node)
//     {
//         return 0;
//     }
//     int width = getWidth(root -> left, node);
//     if(width != INT_MAX)
//     {
//         return width - 1;
//     }
//     width = getWidth(root -> right, node);
//     if(width != INT_MAX)
//     {
//         return width + 1;
//     }
//     return width;
// }

// void topView(binaryTreeNode<int> *root)
// {
//     if(root == nullptr)
//     {
//         return;
//     }
//     stack<int>left;
//     stack<int>right;
//     left.push(0);
//     right.push(0);
//     stack<binaryTreeNode<int>*>lefttop;
//     queue<binaryTreeNode<int>*>righttop;
//     queue<binaryTreeNode<int>*> pending;
//     pending.push(root);
//     pending.push(nullptr);
//     binaryTreeNode<int> *front;
//     while(!pending.empty())
//     {
//         front = pending.front();
//         pending.pop();
//         if(front == nullptr)
//         {
//             if(pending.empty())
//             {
//                 break;
//             }
//             int leftedgewidth = getWidth(root, pending.front());
//             if(leftedgewidth < left.top())
//             {
//                 left.pop();
//                 left.push(leftedgewidth);
//                 lefttop.push(pending.front());
//             }
//             pending.push(nullptr);
//             continue;
//         }
//         else if(pending.front() == nullptr && front != root)
//         {
//             int rightedgewidth = getWidth(root, front);
//             if(rightedgewidth > right.top() && rightedgewidth != INT_MAX)
//             {
//                 right.pop();
//                 right.push(rightedgewidth);
//                 righttop.push(front);
//             }
//         }
//         if(front -> left != nullptr)
//         {
//             pending.push(front -> left);
//         }
//         if(front -> right != nullptr)
//         {
//             pending.push(front -> right);
//         }
//     }
//     while(!lefttop.empty())
//     {
//         cout << lefttop.top() -> data << " ";
//         lefttop.pop();
//     }
//     cout << root -> data << " ";
//     while(!righttop.empty())
//     {
//         cout << righttop.front() -> data << " ";
//         righttop.pop();
//     }
//     return;
// }

int main()
{
    binaryTreeNode<int> *root = takeinput();
    // topView(root);
    return 0;
}

//1 2 4 14 23 37 108 111 115 116 