#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class voldemort
{
    vector< stack<int> > fighters;
    vector < stack <int> > min;
    public:
    voldemort(int totalstacks)
    {
        for(int i = 0; i < totalstacks; i++)
        {
            fighters.push_back(stack<int>());
            min.push_back(stack <int> ());
        }
    }
    void insertheigth(int k, int h)
    {
        if(fighters.at(k - 1).empty())
        {
            min.at(k - 1).push(h);
            fighters.at(k - 1).push(h);
            return;
        }
        if(min.at(k - 1).top() > h)
        {
            min.at(k - 1).push(h);
        }
        fighters.at(k - 1).push(h);
        return;
    }
    void removeheight(int k)
    {
        if(min.at(k - 1).top() == fighters.at(k - 1).top())
        {
            min.at(k - 1).pop();
        }
        fighters.at(k - 1).pop();
        return;
    }
    bool canUseWand()
    {
        int i = 0;
        for(i = 0; i < fighters.size() - 1; i++)
        {
            if(!min.at(i).empty() && min.at(i).top() >= fighters.at(i + 1).top())
            {
                break;
            }
        }
        if(i == fighters.size() - 1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    int numStacks, len, elements;
    cin >> numStacks;
    voldemort v(numStacks);
    for(int i = 1; i <= numStacks; i++)
    {
        cin >> len;
        for(int j = 0; j < len; j++)
        {
            cin >> elements;
            v.insertheigth(i, elements);
        }
    }
    int queries, choice;
    cin >> queries;
    while(queries)
    {
        cin >> choice;
        if(choice == 0)
        {
            int k;
            cin >> k;
            v.removeheight(k);
        }
        else if(choice == 1)
        {
            int k, h;
            cin >> k >> h;
            v.insertheigth(k, h);
        }
        else if(choice == 2)
        {
            if(v.canUseWand())
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        --queries;
    }
    return 0;
}
