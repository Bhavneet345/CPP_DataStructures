#include<iostream>
#include<stack>
using namespace std;

int* stockSpan(int *price, int n)
{
    stack<int> s;
    s.push(0);
    int *span = new int[n];
    span[0] = 1;
    for(int i = 1; i < n; i++)
    {
        if(price[i] > price[s.top()])
        {
            while(!s.empty() && price[i] > price[s.top()])
            {
                s.pop();
            }
            if(s.empty())
            {
                span[i] = i + 1;
            }
            else
            {
                span[i] = i - s.top();
            }
        }
        else
        {
            span[i] = 1;
        }
        s.push(i);
    }
    return span;
}

int main()
{
    int n;
    cin >> n;
    int *price = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    int *span = stockSpan(price, n);
    for(int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }
    return 0;
}