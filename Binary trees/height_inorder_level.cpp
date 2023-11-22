#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

class nodeInfo
{
    public:
    int leftindex;
    int rightindex;
    int height;
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int n)
{
    if(n == 0)
    {
        return 0;
    }
    unordered_map<int, int> inordermap;
    for(int i = 0; i < n; i++)
    {
        inordermap[inorder[i]] = i;
    }
    int maxheight = 0;
    queue<nodeInfo>pending;
    nodeInfo i;
    i.height = 1;
    i.leftindex = 0;
    i.rightindex = n - 1;
    pending.push(i);
    for(int i = 0; i < n; i++)
    {
        int currentpos = inordermap[levelOrder[i]];
        nodeInfo front = pending.front();
        pending.pop();
        if(currentpos > front.leftindex)
        {
            nodeInfo newnode;
            newnode.height = front.height + 1;
            newnode.leftindex = front.leftindex;
            newnode.rightindex = currentpos - 1;
            maxheight = max(maxheight, front.height);
            pending.push(newnode);
        }
        if(currentpos < front.rightindex)
        {
            nodeInfo newnode;
            newnode.height = front.height + 1;
            newnode.leftindex = currentpos + 1;
            newnode.rightindex = front.rightindex;
            maxheight = max(maxheight, front.height);
            pending.push(newnode);
        }
    }
    return maxheight;
}

int main()
{
    vector<int>inorder, levelorder;
    int n, data;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        inorder.push_back(data);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> data;
        levelorder.push_back(data);
    }
    int height = heightOfTheTree(inorder, levelorder, n);
    cout << height;
    return 0;
}