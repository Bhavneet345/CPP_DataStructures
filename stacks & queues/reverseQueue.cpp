#include<iostream>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &input)
{
    if(input.size() <= 1)
    {
        return;
    }
    int first = input.front();
    input.pop();
    reverseQueue(input);
    input.push(first);
}

void print(queue<int> input)
{
    while(!input.empty())
    {
        cout << input.front() << " ";
        input.pop();
    }
    cout << endl;
    return;
}
int main()
{
    queue<int> input;
    int data;
    cin >> data;
    while(data != -1)
    {
        input.push(data);
        cin >> data;
    }
    print(input);
    reverseQueue(input);
    print(input);
    return 0;
}