#include<iostream>
#include<stack>
using namespace std;


bool isBalanced(string str)
{
    if(str.length() <= 1)
    {
        return false;
    }
    stack <char> s1;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '(')
        {
            s1.push(str[i]);
        }
        else if(str[i] == ')')
        {
            if(s1.top() == '(')
            {
                s1.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return s1.empty();
}

int main()
{
    string input;
    cin >> input;
    if(isBalanced(input))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}