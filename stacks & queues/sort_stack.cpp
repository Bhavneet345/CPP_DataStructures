#include<iostream>
#include<stack>
using namespace std;

void sortStack(stack<int> &st)
{
    if(st.empty())
    {
        return;
    }
    int top = st.top();
    st.pop();
    sortStack(st);
    if(st.empty())
    {
        st.push(top);   
    }
    else if(st.top() <= top)
    {
        st.push(top);
    }
    else
    {
        stack<int> temp;
        while(!st.empty() && st.top() > top)
        {
            temp.push(st.top());
            st.pop();
        }
        st.push(top);
        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }
    return;
}

int main()
{
    stack<int> st;
    int data;
    cin >> data;
    while(data != -1)
    {
        st.push(data);
        cin >> data;
    }
    sortStack(st);
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}