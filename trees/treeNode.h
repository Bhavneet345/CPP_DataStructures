#include<iostream>
#include<vector>
using namespace std;
template<typename type>

class treeNode
{
    public:
    vector<treeNode<type>*> children;
    type data;
    treeNode(type data)
    {
        this -> data = data;
    }
};
