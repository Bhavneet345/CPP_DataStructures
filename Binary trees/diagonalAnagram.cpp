#include<iostream>
#include<queue>
#include<unordered_map>
#include "binaryTreeNode.h"
using namespace std;

binaryTreeNode<int>* takeinput()
{
    int data;
    cin >> data;
    if(data == -1)
    {
        return nullptr;
    }
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

void diagonalMapping(binaryTreeNode<int> *root, unordered_map<int, vector<int> >&map, int diagonalval)
{
    if(root == nullptr)
    {
        return;
    }
    map[diagonalval].push_back(root -> data);
    diagonalMapping(root -> left, map, diagonalval + 1);
    diagonalMapping(root -> right, map, diagonalval);
    return;
}

bool checkFrequency(vector<int>root1, vector<int>root2)
{
    if(root1.size() != root2.size())
    {
        return false;
    } 
    unordered_map<int, int>map1, map2;
    for(int i = 0; i < root1.size(); i++)
    {
        map1[root1[i]] += 1;
        map2[root2[i]] += 1; 
    }
    for(int i = 0; i < root1.size(); i++)
    {
        if(map2.find(root1[i]) == map2.end() || map1[root1[i]] != map2[root1[i]])
        {
            return false;
        }
    } 
    return true;
}

bool diagonalAnagram(binaryTreeNode<int>* root1, binaryTreeNode<int>* root2)
{
    if(root2 == nullptr && root1 == nullptr)
    {
        return true;
    }
    if(root1 == nullptr || root2 == nullptr)
    {
        return false;
    }
    unordered_map<int, vector<int> >diagonalsroot1;
    unordered_map<int, vector<int> >diagonalsroot2;
    diagonalMapping(root1, diagonalsroot1, 1);
    diagonalMapping(root2, diagonalsroot2, 1);
    if(diagonalsroot1.size() != diagonalsroot2.size())
    {
        return false;
    }
    for(int i = 0; i < diagonalsroot1.size(); i++)
    {
        if(!checkFrequency(diagonalsroot1[i + 1], diagonalsroot2[i + 1]))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    binaryTreeNode<int> *root1 = takeinput();
    binaryTreeNode<int> *root2 = takeinput();
    if(diagonalAnagram(root1, root2))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}

