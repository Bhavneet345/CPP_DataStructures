#include<iostream>
#include<stack>
using namespace std;

void deleteMiddle(stack<int> &input, int n)
{
    int count = 0;
    stack<int> temp;
    while(count < n / 2)
    {
        temp.push(input.top());
        input.pop();
        count += 1;
    }
    input.pop();
    while(!temp.empty())
    {
        input.push(temp.top());
        temp.pop();
    }
    return;
}

int main()
{
    stack<int> st;
    int data, n, i = 0;
    cin >> n;
    while(i < n)
    {
        cin >> data;
        st.push(data);
        i++;
    }
    deleteMiddle(st, n);
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}