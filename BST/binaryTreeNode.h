#include<iostream>
#include<queue>
using namespace std;
template<typename type>

class binaryTreeNode
{
    public:
    type data;
    binaryTreeNode<type> *left;
    binaryTreeNode<type> *right;
    binaryTreeNode(type data)
    {
        this -> data = data;
        this -> left = nullptr;
        this -> right = nullptr;
    }
};

