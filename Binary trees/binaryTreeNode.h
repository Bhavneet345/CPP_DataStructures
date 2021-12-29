#include<iostream>
using namespace std;
template<typename type>

class binaryTreeNode
{
    public:
    type data;
    binaryTreeNode *left, *right;
    binaryTreeNode(type data)
    {
        this -> data = data;
        this -> left = nullptr;
        this -> right = nullptr;
    }
    ~binaryTreeNode()
    {
        delete this -> left;
        delete this -> right;
    }
};