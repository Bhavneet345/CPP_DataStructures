#include<iostream>
#include<queue>
#include<stack>
#include "BinaryTreeNode.h"
using namespace std;

BinaryTreeNode<int>* takeInput()
{
    int data;
    cin >> data;
    BinaryTreeNode<int> *root = nullptr;
    if(data == -1){
        return root;
    }
    root = new BinaryTreeNode<int>(data);
    queue<BinaryTreeNode<int>*> pending;
    pending.push(root);
    while (!pending.empty()){
        int size = pending.size();
        while(size--){
            BinaryTreeNode<int> *current = pending.front();
            pending.pop();
            cin >> data;
            if(data != -1){
                current -> left = new BinaryTreeNode<int>(data);
                pending.push(current -> left);
            }
            else{
                current -> left = nullptr;
            }
            cin >> data;
            if(data != -1){
                current -> right = new BinaryTreeNode<int>(data);
                pending.push(current -> right);
            }
            else{
                current -> right = nullptr;
            }
        }
    }
    return root;
}

int countNodes(BinaryTreeNode<int> *root)
{
    if(root == nullptr){
        return 0;
    }
    return countNodes(root -> left) + countNodes(root -> right) + 1;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s)
{
    if(root == nullptr){
        return;
    }
    int count = 0;
    int totalcount = countNodes(root);
    stack<BinaryTreeNode<int> *> inorder;
    stack<BinaryTreeNode<int> *> revinorder;
    BinaryTreeNode<int> *current = root;
    while(current != nullptr){
        inorder.push(current);
        current = current -> left;
    }
    current = root;
    while(current != nullptr){
        revinorder.push(current);
        current = current -> right;
    }
    while(count < totalcount - 1){
        BinaryTreeNode<int> *inordertop = inorder.top();
        BinaryTreeNode<int> *revinordertop = revinorder.top();
        if(inordertop -> data + revinordertop -> data == s){
            cout << inordertop -> data << " " << revinordertop -> data << endl;
            BinaryTreeNode<int> *top = inordertop;
            inorder.pop();
            ++count;
            if(top -> right != nullptr){
                top = top -> right;
                while(top != nullptr){
                    inorder.push(top);
                    top = top -> left;
                }
            }
            top = revinordertop;
            revinorder.pop();
            ++count;
            if(top -> left != nullptr){
                top = top -> left;
                while(top != nullptr){
                    revinorder.push(top);
                    top = top -> right;
                }
            }
        }
        else if(inordertop -> data + revinordertop -> data > s){
            BinaryTreeNode<int> *top = revinordertop;
            revinorder.pop();
            ++count;
            if(top -> left != nullptr){
                top = top -> left;
                while(top != nullptr){
                    revinorder.push(top);
                    top = top -> right;
                }
            }
        }
        else{
            BinaryTreeNode<int> *top = inordertop;
            inorder.pop();
            ++count;
            if(top -> right != nullptr){
                top = top -> right;
                while(top != nullptr){
                    inorder.push(top);
                    top = top -> left;
                }
            }   
        }
    }
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int s;
    cin >> s;
    printNodesSumToS(root, s);
    delete root;
    return 0;
}