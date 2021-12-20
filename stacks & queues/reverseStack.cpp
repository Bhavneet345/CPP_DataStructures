#include<iostream>
#include<stack>
using namespace std;

// void helper(stack<int> &input, stack<int> &extra, stack<int> &first, int len)
// {
//     if(len == 1)
//     {
//         return;
//     }
//     for(int i = 1; i <= len; i++)
//     {
//         if(i == 1)
//         {
//             first.push(input.top());
//         }
//         else
//         {
//             extra.push(input.top());
//         }
//         input.pop();
//     }
//     input.push(first.top());
//     first.pop();
//     while(!extra.empty())
//     {
//         input.push(extra.top());
//         extra.pop();
//     }
//     helper(input, extra, first, len - 1);
// }

void reverseStack(stack<int> &input, stack<int> &extra)
{
    if(input.size() <= 1)
    {
        return;
    }
    int last = input.top();
    input.pop();
    reverseStack(input, extra);
    while(!input.empty())
    {
        extra.push(input.top());
        input.pop();
    }
    input.push(last);
    while(!extra.empty())
    {
        input.push(extra.top());
        extra.pop();
    }
    //helper(input, extra, first, innput.size());
}

void print(stack<int> input)
{
    while(!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
    cout << endl;
    return;
}
int main()
{
    stack<int> input, extra;
    int data;
    cin >> data;
    while(data != -1)
    {
        input.push(data);
        cin >> data;
    }
    print(input);
    reverseStack(input, extra);
    print(input);
    return 0;
}