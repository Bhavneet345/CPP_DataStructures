#include<iostream>
#include<stack>
using namespace std;

int minBracketReversal(string input)
{
    stack<char> s;
    int count = 0;
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] != '}')
        {
            s.push(input[i]);
        }
        else
        {
            if(!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(input[i]);
            }
        }
    }
    if(s.empty())
    {
        return count;
    }
    else
    {
        while(!s.empty())
        {
            char c1 = s.top();
            s.pop();
            if(s.empty())
            {
                return -1;
            }
            char c2 = s.top();
            s.pop();
            if(c1 == c2)
            {
                count += 1;
            }
            else
            {
                count += 2;
            }
        }
    }
    return count;
}

int main()
{
    string input;
    cin >> input;
    int count = minBracketReversal(input);
    cout << count;
    return 0;
}