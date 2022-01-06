#include<iostream>
#include<queue>
#include "binaryTreeNode.h"
using namespace std;

class BST
{
    binaryTreeNode<int>* inserthelepr(binaryTreeNode<int> *root, int data)
    {
        if(root == nullptr)
        {
            root = new binaryTreeNode<int>(data);
            return root;
        }
        if (root -> data >= data)
        {
            root -> left = inserthelepr(root -> left, data);
        }
        else if(root -> data < data)
        {
            root -> right = inserthelepr(root -> right, data);
        }
        return root;
    }
    binaryTreeNode<int> *retRightMin(binaryTreeNode<int> *root)
    {
        if(root == nullptr)
        {
            return root;
        }
        binaryTreeNode<int> *min = retRightMin(root -> left);
        if(min == nullptr)
        {
            return root;
        }
        return min;
    }
    binaryTreeNode<int>* deletehelper(binaryTreeNode<int> *root, int data)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if(root -> data > data)
        {
            root -> left = deletehelper(root -> left, data);
        }
        else if(root -> data < data)
        {
            root -> right = deletehelper(root -> right, data);
        }
        else
        {
            if(root -> left == nullptr && root -> right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if(root -> right == nullptr)
            {
                binaryTreeNode<int> *temp = root;
                root = root -> left;
                delete temp;
            }
            else
            {
                binaryTreeNode<int> *tempmin= retRightMin(root -> right);
                root -> data = tempmin -> data;
                root -> right = deletehelper(root -> right, tempmin -> data);
            }
        }
        return root;
    }
    bool searchHelper(binaryTreeNode<int> *root, int data)
    {
        if(root == nullptr)
        {
            return false;
        }
        if(root -> data > data)
        {
            return searchHelper(root -> left, data);
        }
        if(root -> data < data)
        {
            return searchHelper(root -> right, data);
        }
        return true;
    }
    void printhelper(binaryTreeNode<int> *root)
    {
        if(root == nullptr)
        {
            return;
        }
        cout << root -> data << ":";
        if(root -> left != nullptr)
        {
            cout << "L:" << root -> left -> data << ",";
        }
        if(root -> right != nullptr)
        {
            cout << "R:" << root -> right -> data;
        }
        cout << endl;
        printhelper(root -> left);
        printhelper(root -> right);
        return;
    }
    binaryTreeNode<int> *root;
    public:
    BST()
    {
        root = nullptr;
    }
    binaryTreeNode<int> *constructBST()
    {
        cout << "Enter the data value of the root\n";
        int data;
        cin >> data;
        if(data != -1)
        {
            root = new binaryTreeNode<int>(data);
        }
        else
        {
            return root;
        }
        queue<binaryTreeNode<int> *>pending;
        binaryTreeNode<int> *front;
        pending.push(root);
        while(!pending.empty())
        {
            front = pending.front();
            pending.pop();
            cout << "Enter the data value of the left child of " << front -> data << "\n";
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
            cout << "Enter the data value of the right child of " << front -> data << "\n";
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
    void remove(int data)
    {
        if(root == nullptr)
        {
            return;
        }
        root = deletehelper(root, data);
        return;
    }
    void insert(int data)
    {
        root = inserthelepr(root, data);
        return;
    }
    bool search(int data)
    {
        return searchHelper(root ,data);
    }
    void print()
    {
        printhelper(root);
        return;
    }
};

int main()
{
    BST b;
    // b.constructBST();
    // b.print();
    // cout << b.search(1);
    // int data;
    // cin >> data;
    // b.insert(data);
    // b.print();
    // cin >> data;
    // b.remove(data);
    // b.print();
    b.insert(1);
    b.print();
    return 0;
}