#include<iostream>
#include<stack>
using namespace std;

class stackMin
{
    stack<int> s, aux;
    int min;
    public:
    void push(int element)
    {
        if(s.empty())
        {
            min = element;
            s.push(element);
        }
        if(element > min)
        {
            s.push(element);
        }
        else
        {
            s.push((2 * element) - min);
            min = element;
        }
        return;
    }
    void pop()
    {
        if(s.empty())
        {
            cout << -1 << endl;
            return;
        }
        if(s.top() > min)
        {
            s.pop();
        }
        else
        {
            min = 2 * min - s.top();
            s.pop();
        }
    }
    int getMin()
    {
        return min;
    }
};

int main()
{
    stackMin s;
    s.push(6);
    s.push(5);
    s.push(10);
    s.pop();
    s.push(4);
    cout << s.getMin() << endl;
    return 0;
}