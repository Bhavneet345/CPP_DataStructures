#include<iostream>
#include<stack>
using namespace std;

int isAlpha(char element)
{
    int ascii = element;
    if(ascii >= 97 && ascii <= 122)
    {
        return 1;
    }
    return 0;
}

string simplifyDirectory(string str)
{
    stack<char>path;
    bool hold = true;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '/')
        {
            hold = true;
        }
        else if(isAlpha(str[i]))
        {
            if(hold)
            {
                hold = false;
                path.push('/');
            }
            path.push(str[i]);
        }
        else if(str[i] == '.' && str[i + 1] == '.')
        {
            while(!path.empty() && path.top() != '/')
            {
                path.pop();
            }
            if(!path.empty())
            {
                path.pop();
            }
        }
    }
    string destination = "";
    if(path.empty())
    {
        destination = "/";
        return destination;
    }
    while(!path.empty())
    {
        destination = path.top() + destination;
        path.pop();
    }
    return destination;
}

int main()
{
    string input;
    cin >> input;
    string output = simplifyDirectory(input);
    cout << output;
    return 0;
}